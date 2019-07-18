#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *row[30];
int lastrow=0;

void dbs_insert(int v) {
    int *dbs_merge(int *a, int *b, int len);
    int *new_row;
    int i;
    new_row=malloc(sizeof(int));
    new_row[0]=v;
    i=0;
    while (row[i]!= NULL) {
        new_row=dbs_merge(row[i],new_row,1<<i);
        row[i]=NULL;
        i++;
    }
    row[i]=new_row;

    if (i>lastrow) lastrow=i;
}

int *dbs_merge(int *a, int *b, int len) {
    int ai=0;
    int bi=0;
    int ci=0;
    int *c;
    c=malloc((2*len)*sizeof(int));
    while (ai <len && bi < len) {
        if (a[ai]<=b[bi]) {
            c[ci++]=a[ai++];
        } else {
            c[ci++]=b[bi++];
        }
    }
    while (ai<len)
        c[ci++]=a[ai++];
    while (bi<len)
        c[ci++]=b[bi++];
    free(a);
    free(b);
    return c;
}

void dbs_print(FILE* out)
{
    int i=0,l,j=0;
    int* a;
    int len;
    while(i<=lastrow)
    {
        a=row[i];
        len =1<<i;

        for(j=0;j<len;j++)
        {   
            if(a!=NULL)
            fprintf(out,"%d ",a[j]);
        }
        i++;
    }
    fprintf(out,"\n");
}
int binarySearch(int *arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
   
        if (arr[mid] == x) 
            return mid; 
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 

int getdigits(char* str)
{
	int i,m=0;

	for(i=0;i<(strlen(str)-1);i++)
		m=(str[i]-'0')+(10*m);

	return m;
}

int main()
{
FILE* in = fopen("input.txt","r");
FILE* out= fopen("output.txt","a");
out= fopen("output.txt","w");

char str[100],digits[100];
int digit;
int i=0,l,j=0;
int* a;
int pos=-1,flag=0;

while(fgets(str,99,in)!=NULL)
{
    switch(str[0])
    {

        case'i':
                for(i=1;str[i]==' ';i++);

                for(j=0;i<strlen(str);i++,j++)
                digits[j]=str[i];

                digits[j]='\0';

                digit=getdigits(digits);
                dbs_insert(digit);
                break;

        case'p':
                dbs_print(out);
                break;
        case's':
                for(i=1;str[i]==' ';i++);

                for(j=0;i<strlen(str);i++,j++)
                digits[j]=str[i];

                digits[j]='\0';

                digit=getdigits(digits);

                flag=0;
                i=0;
                 while(i<=lastrow&&flag==0)
                {
                    a=row[i];
                    l=1<<i;
                    if(a!=NULL)
                    pos=binarySearch(a,0,l,digit);

                    if(pos!=-1)
                    flag=1;

                    i++;
                }
                if(pos!=-1)
                    fprintf(out,"%d\n",pos);
                else
                    fprintf(out,"NIL\n");
                    
                
                
                break;

        default:
                printf("Not found");
    }   

    
}
return 0;
}
