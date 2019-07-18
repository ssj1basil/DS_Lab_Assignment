#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>


int ipow(int base,int exp)
{
if(exp==0)
	return 1;
int i;
for(i=1;i<exp;i++)
	base*=base;

return base;
}

struct tree		
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

int maxwidth(struct tree* root) 
{ 
  int getwidth(struct tree* root,int level);
  int height(struct tree* root);
  int maxWidth = 0;    
  int width; 
  int h = height(root); 
  int i; 
    
  for(i=1; i<=h; i++) 
  { 
    width = getwidth(root, i); 
    if(width > maxWidth) 
      maxWidth = width; 
  }      
    
  return maxWidth; 
} 
  
int getwidth(struct tree* root, int level) 
{ 
      
  if(root == NULL) 
    return 0; 
    
  if(level == 1) 
    return 1; 
              
  else if (level > 1) 
    return getwidth(root->left, level-1) +  
             getwidth(root->right, level-1); 
} 


int height(struct tree* root)
{
if(root==NULL)
	return 0;
else
if(root->left!=NULL||root->right!=NULL)
{
int left=height(root->left);
int right=height(root->right);

if(left>right)
	return(left+1);
else
	return(right+1);
}


}


void print_tree(struct tree* t)	
{

		
		if(t==NULL)
			printf("NULL");
		if(t!=NULL)
		{
		printf("(%d",t->data);
		//printf("(");
		if(t->left!=NULL||t->right!=NULL)
		{print_tree(t->left);
		print_tree(t->right);
		}
		printf(")");
		}
}

int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
} 


int diameter(struct tree * root) 
{ 

   if (root == NULL) 
     return 0; 
 

   else
	  if(root->left!=NULL||root->right!=NULL)
{ 
  int lheight = height(root->left); 
  int rheight = height(root->right); 
  
 
  int ldiameter = diameter(root->left); 
  int rdiameter = diameter(root->right); 
  


 return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}
}

int main()
{
struct tree* root;
char str[1000],stree[1000];
FILE* in=fopen("input.txt","r");
int i=1,j=0;
FILE* out=fopen("output.txt","w");

while(fgets(str,1000,in)!=NULL)
{
for(i=1,j=0;i<(strlen(str)-2);i++,j++)
	stree[j]=str[i];
stree[j]='\0';


root=create_tree(stree,0,j-1);


fprintf(out,"%d ",height(root));
fprintf(out,"%d ",diameter(root));
fprintf(out,"%d",maxwidth(root));
}
fclose(out);
return 0;}
