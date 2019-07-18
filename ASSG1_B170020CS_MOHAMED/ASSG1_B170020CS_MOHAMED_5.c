#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<limits.h>  

int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

struct node
{

		int data;
		struct node *left,*right;
};

struct node* newnode(int data)
{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->left=temp->right=NULL;
		return temp;
}

/*
struct node* constructbst(int* index,int low,int size,int* data)
{


int i;

if(*index>=size || low>size)
		return NULL;

struct node* root= newnode(data[*index]);
		*index=*index+ 1;

if(low==(size-1))
		return root;

for(i=low;i<size;i++)
	if(data[i]>root->data)
			break;

root->left= constructbst(index,*index,i-1,data);
root->right= constructbst(index,i,size,data);

return root;
}*/

struct node* constructbst (int pre[], int* preIndex, 
                                int low, int high, int size) 
{ 
    if (*preIndex >= size || low > high) 
        return NULL; 
  
    struct node* root = newnode ( pre[*preIndex] ); 
    *preIndex = *preIndex + 1; 
  
  
    if (low == high) 
        return root; 
   
    int i; 
    for ( i = low; i <= high; ++i ) 
        if ( pre[ i ] > root->data ) 
            break; 
  
    root->left = constructbst ( pre, preIndex, *preIndex, i - 1, size ); 
    root->right = constructbst ( pre, preIndex, i, high, size ); 
  
    return root; 
} 

void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
	 {
	 	printf("()");
		return ;
	 } 
  
     printf("(%d ", node->data);   
 
     printPreorder(node->left);   
 
     printPreorder(node->right); 
	 printf(")");

}


int main()
{

		int num=0,i=0,j=-1,digit=0,temp,index=0;
		int data[100]={0};
		FILE *in;
		in=fopen("input.txt","r");
		char str[100];

		
		while(fgets(str,100,in)!=NULL)
		{

				digit=0;
				for(i=strlen(str),num=0;i>=0;i--)
				{
						if(isdigit(str[i]))
						{
								num+=(str[i]-'0')*ipow(10,digit);
								digit++;
						}	
				}

				temp=num;
				printf("\nnum=%d ",num);

				fgets(str,100,in);
				for(i=strlen(str)-2;str[i]!='\n'&&str[i]!='\0';i--)
				{		
						temp--;
						digit=0;
						while(str[i]!=' '&&str[i]!='\n')
						{
								if(isdigit(str[i]))
										data[temp]+=(str[i]-'0')*ipow(10,digit);

								i--;
								digit++;
						}

				}

		}


		struct node* root=constructbst(data,&index,0,num-1,num);

		for(i=0;i<num;i++)
		printf("%d ",data[i]);

		printPreorder(root);

		return 0;}
