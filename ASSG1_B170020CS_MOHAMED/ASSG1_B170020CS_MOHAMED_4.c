#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

FILE* out;
//out=fopen("output.txt","w");

struct node
{
	int data;
	struct node *left, *right;
};


struct node* newnode(int key)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=temp->right=NULL;

	return temp;
}



struct node* insert(struct node* root,int key)
{
	if(root==NULL)
		return newnode(key);

	if(root->data<key)
		root->right=insert(root->right,key);
	else
		if(root->data>=key)
			root->left=insert(root->left,key);

	return root;

}

int search(struct node* root,int key)
{

	if(root==NULL)
		return 0;

	if(key==root->data)
		return 1;
	else 
		if(key>root->data)
			return search(root->right,key);
		else
			return search(root->left,key);


}

int findmin(struct node* root)
{
	if(root==NULL)
	{
		return INT_MIN;
	}
	while(root->left!=NULL)
		root=root->left;

	return root->data;
}


struct node* findminnode(struct node* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	while(root->left!=NULL)
		root=root->left;

	return root;
}

int findmax(struct node* root)
{
	if(root==NULL)
	{
		return INT_MIN;
	}
	while(root->right!=NULL)
		root=root->right;

	return root->data;
}

int predecessor(struct node* root,int key)
{

	int pre;
	if(root==NULL)
		return INT_MIN;

	if(root->data==key)
	{
		if(root->left!=NULL)
		{struct node* temp=root;
			if(temp->right!=NULL)
				temp=temp->right;
			pre=temp->data;
			return pre;
		}
		else
			return INT_MIN;
	}
	else
		if(root->data>key)
			return	predecessor(root->left,key);
		else
			return	predecessor(root->right,key);


}

int successor(struct node* root,int key)
{

	int suc;
	if(root==NULL)
		return INT_MIN;

	if(root->data==key)
	{
		if(root->right!=NULL)
		{struct node*temp=root;
			if(temp->left!=NULL)
				temp=temp->left;
			suc=temp->data;
			return suc;
		}
		else
			return INT_MIN;
	}
	else
		if(root->data>key)
		{
			suc=root->data;
			suc=successor(root->left,key);
		}
		else
			suc=successor(root->right,key);

	return suc;


}

struct node* deletenode(struct node* root,int key)
{

	struct node* temp;
	if(root==NULL)
		return NULL;

	if(root->data==key)
	{
		if(root->left==NULL)
		{
			temp=root->right;
			free(root);
			return temp;
		}

		if(root->right!=NULL)
		{
			temp=root->left;
			free(root);
			return temp;
		}

		temp=findminnode(root->right);
		root->data=temp->data;
		root->right=deletenode(root->right,temp->data);

	}

	else
		if(root->data>key)
			root->left=deletenode(root->left,key);
		else
			root->right=deletenode(root->right,key);

	return root;
}

void inorder(struct node* root,FILE* out)
{
	if(root==NULL)
		return ;

	//out=fopen("output.txt","a+");

	inorder(root->left,out);
	fprintf(out,"%d ",root->data);
	//printf("%d ",root->data);
	inorder(root->right,out); 

	//fclose(out);

}



void preorder(struct node* root,FILE* out)
{
	if(root==NULL)
		return ;

	//out=fopen("output.txt","a+");
	//printf("%d ",root->data);

	fprintf(out,"%d ",root->data);
	preorder(root->left,out);
	preorder(root->right,out); 

	//fclose(out);

}


void postorder(struct node* root,FILE* out)
{
	if(root==NULL)
		return ;

	//out=fopen("output.txt","a+");
	

	postorder(root->left,out);
	postorder(root->right,out); 
	fprintf(out,"%d ",root->data);
	//printf("%d ",root->data);

	//fclose(out);

}


int ipow(int base,int exp)
{
	int i;
	if(exp==0)
		return 1;
	else
		for(i=1;i<exp;i++)
			base*=base;
	return base;
}

int getdata(char *str)
{
	int i,digits=-1,data=0;

	for(i=5;str[i]!='\n'&&str[i]!='\0';i++)
	{
		digits++;
	}

	for(i=5;digits>=0;digits--,i++)
	{
		data+=(str[i]-'0')*(ipow(10,digits));
	}

	return data;
}

int main()
{

	struct node* root=(struct node*)malloc(sizeof(struct node));
	root=NULL;

	FILE *in,* out;
	in=fopen("input.txt","r");
	out=fopen("output.txt","a+");

	char str[100],sub[6];
	int i=0,data;

	while(fgets(str,100,in)!=NULL)
	{
		for(i=0;i<4;i++)
			sub[i]=str[i];
			sub[i]='\0';

		if(strcmp(sub,"srch")==0)
		{
			//printf("\nsearch");
			data=getdata(str);
			if(search(root,data))
				fprintf(out,"FOUND\n");
			else
				fprintf(out,"NOT FOUND\n");	

		}
		else
			if(strcmp(sub,"insr")==0)
			{
					//printf("\ninsr");
					data=getdata(str);
				root=insert(root,data);
			}
			else
				if(strcmp(sub,"minm")==0)				
				{
						//printf("\nminm");
						if(findmin(root)==INT_MIN)
						fprintf(out,"NIL\n");
					else
						fprintf(out,"%d\n",findmin(root));

				}

				else
					if(strcmp(sub,"maxm")==0)
					{
							//printf("\nmaxm");
							if(findmax(root)==INT_MIN)
							fprintf(out,"NIL\n");
						else
							fprintf(out,"%d\n",findmax(root));

					}
					else
						if(strcmp(sub,"succ")==0)
						{
								//printf("\nsucc");
								data=getdata(str);
							if(root==NULL)
								fprintf(out,"NOT FOUND\n");
							else
								if(successor(root,data)==INT_MIN)
									fprintf(out,"NIL\n");
								else
									fprintf(out,"%d\n",successor(root,data));								
						}
						else
							if(strcmp(sub,"pred")==0)
							{
									//printf("\npred");
									data=getdata(str);
								if(root==NULL)
									fprintf(out,"NOT FOUND\n");
								else
									if(predecessor(root,data)==INT_MIN)
										fprintf(out,"NIL\n");
									else
										fprintf(out,"%d\n",predecessor(root,data));								
							}


							else
								if(strcmp(sub,"delt")==0)
								{
										//printf("\ndelt");
										data=getdata(str);
									root=deletenode(root,data);	
								}

								else
									if(strcmp(sub,"inor")==0)
									{
											//printf("\ninor");
											inorder(root,out);	
										fprintf(out,"\n");								
									}
									else
										if(strcmp(sub,"prer")==0)
										{
												//printf("\nprer");
												preorder(root,out);
											fprintf(out,"\n");
										}
										else
											if(strcmp(sub,"post")==0)
											{
													//printf("\npost");
													postorder(root,out);
												fprintf(out,"\n");
											}
											else
												if(strcmp(sub,"stop")==0)
													return 0;




	}

	fclose(out);
	return 0;
}
