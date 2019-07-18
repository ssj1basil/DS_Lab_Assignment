#include<stdio.h>
#include<string.h>

int getdigits(char* str)
{
	//printf("\nin getdigits function");

	//printf("\n%lu",strlen(str));

	int i,m=0;

	for(i=0;i<strlen(str);i++)
		m=(str[i]-'0')+(10*m);


	return m;
}

int secondmin(int A[] ,int size)
{
int i,j;
int binaryheap[2*size-1];

for(i=size-1,j=0;i<(2*size-1);i++,j++)
binaryheap[i]=A[j];

for(i=size-2;i>=0;i--)
{
if(binaryheap[2*i+1]>binaryheap[2*i+2])
binaryheap[i]=binaryheap[2*i+2];
else
binaryheap[i]=binaryheap[2*i+1];

}
//for(i=0;i<(2*size-1);i++)
//printf(" %d,",binaryheap[i]);


if(binaryheap[0]==binaryheap[1])
{
	if(binaryheap[0]==binaryheap[3])
		return binaryheap[4];
	else
		return binaryheap[3];
}


if(binaryheap[0]==binaryheap[2])
{
if(binaryheap[0]==binaryheap[5])
	return binaryheap[6];
else
	return binaryheap[5];
}

}

int main()
{
int a[100];
int i,j,secmin,index;
FILE* in;
FILE* out;
in=fopen("input.txt","r");
out=fopen("output.txt","w");

char ch[100],digits[10];

while(fgets(ch,99,in)!=NULL)
{

for(i=0,index=0;ch[i]!='\0';i++)
{

if(ch[i]==' '||ch[i]=='\n')
{
	digits[j]='\0';
	a[index]=getdigits(digits);
	index++;
	//printf("\nindex=%d,a[index]=%d",index-1,a[index-1]);
	j=0;
	continue;
}
else
{
digits[j]=ch[i];
j++;
}
}
secmin=secondmin(a,index);
fprintf(out,"%d\n",secmin);


}

return 0;}
