#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

FILE* out;

int ipow(int base,int exp)
{
if(exp==0)
	return 1;
int i;
for(i=1;i<exp;i++)
	base*=base;

return base;
}

struct tree				//Done
{
	int data;
	struct tree *left,*right;
};

struct tree* newnode(int data)
{
struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
temp->data=data;
temp->left=temp->right=NULL;
return temp;

}

struct tree* create_tree(char stree[],int low,int high)
{

struct tree* root;	
if(low>high)
	return NULL;

/*printf("\nlow=%c",stree[low]);
printf("\ndata=%d",stree[low]-'0');
*/

int temp=low,digits=-1,num=0,flag=0;



if(stree[low]=='('&&stree[low+1]==')')
{
root=NULL;
return root;
}

for(;stree[temp]!='('&& stree[temp]!=')';temp++)
	digits++;

temp=low;
//printf("\n%d",temp);

for(;digits>=0;temp++,digits--)
{	
	flag=1;
	num+=(stree[temp]-'0')*ipow(10,digits);
}

//printf("\nnum=%d",num);
low=temp-1;

if(flag==1)
{root=newnode(num);
//printf("\n tree=%d",root->data);
}

int count=0,i=low+1,index=INT_MIN;

if(stree[low+1]=='('&& low+1<=high)
	{for(;i<=high;i++)
		{if(stree[i]=='(')
			{
				//printf("\ncount++");
				count++;
			}
		else
			if(stree[i]==')')
			{
				//printf("\ncount--");
				count--;
			}
		if(count==0)
		break;
		}
	}

index=i;
//printf("\nindex=%d",index);

if(index!=INT_MIN&&flag==1)
{
root->left= create_tree(stree,low+2,index-1);
root->right= create_tree(stree,index+2,high-1);
}

return root;
}

void print_tree(struct tree* t,FILE* out)	//Dis
{

		
		printf("(");
		if(t!=NULL)
		{
		fprintf(out,"%d ",t->data);
		printf("%d",t->data);
		//printf("(");
		if(t->left!=NULL||t->right!=NULL)
		{print_tree(t->left,out);
		print_tree(t->right,out);
		}
		//printf(")");
		}
		printf(")");
}


void mirror(struct tree* t)		//Done
{
	void * temp;
	if(t==NULL)
		return;
	temp=t->right;
	t->right=t->left;
	t->left=temp;
	mirror(t->left);
	mirror(t->right);
}


int main()				//Done
{
	FILE *input=fopen("input.txt","r");
	char ch,stree[100],str[100];
	int i=1,j=0;
	struct tree* root;
	out=fopen("output.txt","w");
	
	if(input==NULL)
	{
	printf("\nFile doesn't exist");
	return 0;
	}
	while(fgets(str,100,input)!=NULL)
	{
		switch(str[0])
		{
			case 'c':
				for(j=0,i=2;i<(strlen(str)-2);i++,j++)
					stree[j]=str[i];
					stree[j]='\0';
					
				//printf("\n%s",stree);
				
				root=create_tree(stree,0,j-1);
				break;
			case 'p':
				//printf("(");
				print_tree(root,out);
				printf("\n");
				break;
			case 'm':
				mirror(root);
				break;
			case 's':return 0;
		}
	}
	fclose(out);
}
