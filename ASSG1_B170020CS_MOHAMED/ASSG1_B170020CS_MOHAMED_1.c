#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>

struct node
{
	int data;
	struct node* next;
};

void add_node(struct node** head_ref, int new_data) 
{ 
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
    struct node *last = *head_ref;
    new_node->data  = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
 while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     
} 

void print(struct node* head)
{
	struct node* temp=head;

	FILE *out;
	out=fopen("output.txt","a+");


	while(temp!=NULL)
	{
		fprintf(out,"%d ",temp->data);
		temp=temp->next;
	}


	fputs("\n",out);
	fclose(out);
}


int h_occur(struct node *head) { 
  struct node *p = head; 
  int max = -1;
  int res;
  while (p != NULL) { 
  
    struct node *q = p->next; 
    int count = 1; 
    while (q != NULL) { 
      if (p->data == q->data) 
        count++; 
  
      q = q->next; 
    } 
  
    if (max < count) { 
      res = p->data; 
      max = count; 
    } 
  
    p = p->next; 
  } 
  
  return res; 
} 



int main()
{
	struct node* head=NULL;
	char op;
	int num,i=-1,key,res;
	FILE *in;
	in=fopen("input.txt","r");
	if(in==NULL)
	{
		printf("File doesn't exist");
		return 0;
	}

	while(!feof(in))
	{
		op=fgetc(in);
		switch(op)
		{
			case 'c': 
				while(op!='\n')
				{ 	
					op=fgetc(in);		

					if(isdigit(op))
					{
						i++;
						num=(op-'0');	
					}
				}
				op=fgetc(in);
				
				while(op!='\n'&&op!='\0')
				{

					i=-1;
					while(op!=' '&&op!='\n')
					{
						if(isdigit(op))
						{
							i++;	
							key=(op-'0');

						}

						op=fgetc(in);
					}
					add_node(&head,key);
					if(op!='\n')
					op=fgetc(in);
				}


				break;					


			case 'p': print(head);
				  break;


			case 'h': res=h_occur(head);
					  FILE *out;
        out=fopen("output.txt","a+");fprintf(out,"%d \n",res);fclose(out);
				  break; 


			case 'a': op=fgetc(in);
				  i=-1;
				  while(op!='\n'&&op!='\0')
				  { 

					  if(isdigit(op))
					  {
						  i++;
						  key=(op-'0');
					  }

					  op=fgetc(in);
				  }
				  add_node(&head,key);	 
				  break;



		};

	}



	return 0;}




