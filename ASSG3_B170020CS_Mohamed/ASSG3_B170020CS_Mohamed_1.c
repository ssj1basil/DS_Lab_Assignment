#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node *set1[10000]={NULL};
struct node *set2[10000]={NULL};
struct node *set3[10000]={NULL};
struct node *set4[10000]={NULL};

int count1=0;
int count2=0;
int count3=0;
int count4=0;

FILE*out;

typedef struct node
{
    int data;
    int rank;
    struct node* parent;
}node;

void MAKE_SET1(int k)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=k;
    temp->rank=0;
    temp->parent=temp;
    set1[k]=temp;
}
void MAKE_SET2(int k)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=k;
    temp->rank=0;
    temp->parent=temp;
    set2[k]=temp;
}
void MAKE_SET3(int k)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=k;
    temp->rank=0;
    temp->parent=temp;
    set3[k]=temp;
}
void MAKE_SET4(int k)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=k;
    temp->rank=0;
    temp->parent=temp;
    set4[k]=temp;
}

int FIND_SET1(int j)
{
    node*temp6=set1[j];
    while(1)
    {
        if(temp6->parent==temp6)
        {
            count1++;
            return temp6->data;
        }
        else
        {
            count1++;
            temp6=temp6->parent;
        }
    }
}

int FIND_SET2(int j)
{
    node*temp5=set2[j];
    while(1)
    {
        if(temp5->parent==temp5)
    {
        count2++;
        return temp5->data;
    }
    else
    {
        count2++;
        temp5=temp5->parent;
    }
    }
}

node* FIND_SET3(int j)
{
    count3++;
    node*temp=set3[j];
    if(temp->parent!=temp)
    {
        temp->parent=FIND_SET3(temp->parent->data);
    }
     return temp->parent;
    }

node* FIND_SET4(int j)
{
    count4++;
    node*temp=set4[j];
    if(temp->parent!=temp)
    {
        temp->parent=FIND_SET4(temp->parent->data);
    }
    return temp->parent;
}


void UNION_1(int k1,int k2)
{
    int t1=FIND_SET1(k1);
    int t2=FIND_SET1(k2);
    set1[t2]->parent=set1[t1];

    printf("%d ",set1[t1]->data);

}

void UNION_2(int k3,int k4)
{
    int t3=FIND_SET2(k3);
    int t4=FIND_SET2(k4);
    if(set2[t3]->rank >= set2[t4]->rank)
    {
        set2[t4]->parent=set2[t3];
        printf("%d ",set2[t3]->data);
    }
    if (set2[t3]->rank<set2[t4]->rank)
    {
        set2[t3]->parent=set2[t4];
        printf("%d ",set2[t4]->data);
    }
    if(set2[t3]->rank==set2[t4]->rank)
    {
        set2[t3]->rank++;
    }
}
void UNION_3(int k5,int k6)
{
    node*t5=FIND_SET3(k5);
    node*t6=FIND_SET3(k6);
    t6->parent=t5;

    printf("%d ",t5->data);
}

void UNION_4(int k7,int k8)
{
    node* t7=FIND_SET4(k7);
    node* t8=FIND_SET4(k8);
    if(t7->rank >= t8->rank)
    {
        t8->parent=t7;
        printf("%d ",t7->data);
    }

    if (t7->rank < t8->rank)
    {
        t7->parent=t8;
        printf("%d ",t8->data);
    }


    if(t7->rank ==t8->rank)
    {
        t7->rank++;
    }
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
int num1,num2;
char ch;
int t1,t2,i,j;
char str[100],digits[100],digits1[100];


node*t3,*t4;
FILE*in;

in=fopen("input.txt","r");
out=fopen("output.txt","a");
out=fopen("output.txt","w");

while(fgets(str,99,in)!=NULL)
{
switch(str[0])
{
case 'm':

            for(i=1;str[i]==' ';i++);

            for(j=0;i<strlen(str);i++,j++)
            digits[j]=str[i];

            digits[j]='\0';

            num1=getdigits(digits);

            MAKE_SET1(num1);
            MAKE_SET2(num1);
            MAKE_SET3(num1);
            MAKE_SET4(num1);
            printf("%d\n",num1);
            break;
            
case 'u':

            for(i=1;str[i]==' ';i++);

            for(j=0;str[i]!=' ';i++,j++)
                digits[j]=str[i];
                
                digits[j]='\n';

                digits[j+1]='\0';

                num1=getdigits(digits);
                
                printf("%d num1",num1);

            for(;str[i]==' ';i++);

            for(j=0;i<strlen(str);i++,j++)
                digits1[j]=str[i];


                digits1[j]='\0';

              
            
            num2=getdigits(digits1);
              printf("%d num2",num2);

            if(set1[num1]==NULL ||set1[num2]==NULL)
            {
            printf("ERROR\n");
            break;
            }
            UNION_1(num1,num2);
            UNION_2(num1,num2);
            UNION_3(num1,num2);
            UNION_4(num1,num2);
            printf("\n");
            break;
            
case 'f':
            for(i=1;str[i]==' ';i++);


            for(j=0;str[i]!=' ';i++,j++)
                digits[j]=str[i];

                digits[j]='\0';

                num1=getdigits(digits);

            printf("\n\n%d",num1);


            if(set1[num1]==NULL)
            {
                printf("NOT FOUND\n");
                break;
            }

            t1=FIND_SET1(num1);
            printf("%d ",set1[t1]->data);
            t2=FIND_SET2(num1);
            printf("%d ",set2[t2]->data);
            t3=FIND_SET3(num1);
            printf("%d ",t3->data);
            t4=FIND_SET4(num1);
            printf("%d ",t4->data);
            printf("\n");
            break;

case 's':

            printf("%d ",count1);
            printf("%d ",count2);
            printf("%d ",count3);
            printf("%d",count4);
            exit(0);
            
}

}
return 0;
}
