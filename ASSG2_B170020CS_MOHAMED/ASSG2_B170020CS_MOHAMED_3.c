 #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>

  struct hash *hashtable = NULL;

  int count =13;

  struct node {
        int n1,n2;
        struct node *next;
  };

  struct node * create(int n1, int n2) {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->n1 = n1;
        newnode->n2 = n2;
        newnode->next = NULL;
        return newnode;
  }


  struct hash {
        struct node *head;
        int count;
  };

  void insert(int n1,int n2) 
{

		//printf("\nin insert function");
        int sub=n1>n2?n1-n2:n2-n1;
        int index = (((n1+n2)%count)+sub)%count;
        //printf("%d\n",sub);
        struct node *newnode =  create(n1,n2);
        
        if (!hashtable[index].head) {
                hashtable[index].head = newnode;
                hashtable[index].count = 1;
                return;
        }
        
        newnode->next = (hashtable[index].head);
    
        hashtable[index].head = newnode;
        hashtable[index].count++;
        return;
  }

  void print(FILE* out) {
        struct node *Node,*t;
	for (int i=0;i<10;i++) {
		Node = hashtable[i].head;
		while(Node!= NULL) {
			t=Node->next;
			while(t!=NULL) {
				if ((Node->n1==t->n2)&&(Node->n2==t->n1)) {
					fprintf(out,"(%d,%d)\n", t->n1,t->n2);
				}
				t=t->next;
			}
			Node = Node->next;
		}
	}
	return;
  }

int getdigits(char* str)
{
	int i,m=0;

	for(i=0;i<strlen(str);i++)
		m=(str[i]-'0')+(10*m);


	return m;
}

  int main() {
	  	FILE* out=fopen("output.txt","w");
        int n,n1,n2,i,j;
        hashtable = (struct hash *)calloc(13, sizeof (struct hash));
        for(int i=0;i<count;i++)
			{hashtable[i].head=NULL;
			hashtable[i].count=0;}
        
		FILE* in=fopen("input.txt","r");	
		char ch[100],digits[10];

		while (fgets(ch,99,in)!=NULL) 
		{
			switch(ch[0])
			{
				case's':for(i=2,j=0;ch[i]!=',';i++,j++)
							digits[j]=ch[i];
						digits[j]='\0';
						n1=getdigits(digits);
					
						i++;
						for(j=0;ch[i]!=')'&&ch[i]!='\0';i++,j++)
							digits[j]=ch[i];
						digits[j]='\0';
						n2=getdigits(digits);
						
						insert(n1,n2);
						break;
				case'p':print(out);

						break;
				case'e':exit(0);
				
				default:printf("\nWrong option");
						break;
			
			};
               
        }
        return 0;
  }
