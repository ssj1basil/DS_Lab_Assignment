#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node* set1[100]={NULL};
struct node* set2[100]={NULL};
struct set;

typedef struct node
{
int data;
struct node* next;
struct set* ptr;
}node;

typedef struct set
{
int size;
node* head;
node* tail;
}set;

void MAKE_SET1(int num1)
{
	node*temp1=(node*)malloc(sizeof(node));
	set*temp2=(set*)malloc(sizeof(set));
	
	temp1->data=num1;
	temp1->next=NULL;
	temp1->ptr=temp2;
	
	temp2->head=temp1;
	temp2->tail=temp1;
	temp2->size=1;

	set1[num1]=temp1;
}

void MAKE_SET2(int num1)
{
	node*temp1=(node*)malloc(sizeof(node));
	set*temp2=(set*)malloc(sizeof(set));
	
	temp1->data=num1;
	temp1->next=NULL;
	temp1->ptr=temp2;
	
	temp2->head=temp1;
	temp2->tail=temp1;
	temp2->size=1;
	
	set2[num1]=temp1;
}

int FIND_SET1(int num1)
{
	node*temp=set1[num1];
	return temp->ptr->head->data;
}

int FIND_SET2(int num1)
{
	node*temp=set2[num1];
	return temp->ptr->head->data;
}

int UNION_1(int num1,int num2)
{
	node* temp1=set1[num1];
	node* temp2=set1[num2];
	
	set* pen1=temp1->ptr;
	set* pen2=temp2->ptr;
	
	pen1->tail->next=pen2->head;
	pen1->tail=pen2->tail;
	
	node* temp3=pen2->head;
	while(temp3!=NULL)
	{
		temp3->ptr=pen1;
		temp3=temp3->next;
	}
	return pen1->head->data ;
}

set* revert(int num1,int num2)
{
	node* temp1=set2[num1];
	node* temp2=set2[num2];
	
	set* pen1=temp1->ptr;
	set* pen2=temp2->ptr;
	
	pen1->tail->next=pen2->head;
	pen1->tail=pen2->tail;
	
	node* temp3=pen2->head;
	while(temp3!=NULL)
	{
		temp3->ptr=pen1;
		temp3=temp3->next;
	}
	return pen1;
}

int UNION_2(int num1,int num2)
{
	node*temp1=set2[num1];
	node*temp2=set2[num2];
	
	set* pen1=temp1->ptr;
	set* pen2=temp2->ptr;
	set* l=(set*)malloc(sizeof(set));
	
	if(pen1->size >pen2->size)
	{
		l=revert(num1,num2);
	}

	if(pen1->size <pen2->size)
	{
		l=revert(num2,num1);
	}

	if(pen1->size == pen2->size)
	{
		if(FIND_SET2(num1)<FIND_SET2(num2))
		{
			l=revert(num1,num2);
		}
		else
		{
			l=revert(num2,num1);
		}
	}

	l->size=pen1->size+pen2->size;

	return l->head->data;
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
FILE* in,*out;
int ans1,ans2,i,j;
char ch;
in=fopen("input.txt","r");
out=fopen("output.txt","a");
out=fopen("output.txt","w");

int num1,num2;

char str[100],digits[100],digits1[100];

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
							
					fprintf(out,"%d\n",num1);
					break;
		
		case 'u':
					for(i=1;str[i]==' ';i++);

                	for(j=0;str[i]!=' ';i++,j++)
               		 digits[j]=str[i];
					 digits[j]='\n';

               	     digits[j+1]='\0';

              		 num1=getdigits(digits);
					 

					for(;str[i]==' ';i++);

                	for(j=0;i<strlen(str);i++,j++)
               		 digits1[j]=str[i];


               		 digits1[j]='\0';

					
                	num2=getdigits(digits1);

					if(set1[num1]==NULL || set1[num2]==NULL)
					{
						printf("ERROR\n");
								break;
					}
					ans1=UNION_1(num1,num2);
					fprintf(out,"%d ",ans1);
				
					ans2=UNION_2(num1,num2);
					fprintf(out,"%d",ans2);
				
					fprintf(out,"\n");
						break;
					
		case 'f':
					for(i=1;str[i]==' ';i++);

                	for(j=0;i<strlen(str);i++,j++)
                	digits[j]=str[i];

                	digits[j]='\0';

               		num1=getdigits(digits);

					if(set1[num1]==NULL)
					{
					printf("NOT FOUND\n");
							break;
					}
					ans1=FIND_SET1(num1);
					fprintf(out,"%d ",ans1);
				
					ans2=FIND_SET2(num1);
					fprintf(out,"%d",ans2);
				
					fprintf(out,"\n");
						
					break;
					

		case 's':
					exit(0);
	}
}
return 0;
}
