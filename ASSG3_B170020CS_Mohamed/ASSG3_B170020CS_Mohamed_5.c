#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int print(int *ptr)
{
 int n;
 printf("(");
 for(int i=0;i<n-1;i++)
     printf("%d ",ptr[i]);
 printf("%d)\n",ptr[n-1]);
}

int app(int *A,int x)
{
 int n=sizeof(A)/sizeof(int);
 A=(int*) realloc(A,(n+1)*sizeof(int));
 A[n]=x;
 print(A);
 free(A);
}


int conc(int *A,int *B)
{
 
 print(A);
 free(A);
 free(B);
}

int mem(int *A,int x)
{
 int r=0;
 int n=sizeof(A)/sizeof(int);
 for(int i=0;i<n;i++)
  {
   if(A[i]==x)
    {
     r=1;
     break;
    }
  }
 free(A);
 printf("%d\n",r);
}

int len(int *A)
{
 int n=sizeof(A)/sizeof(int);
 printf("%d\n",n);
 free(A);
}


int sli(int *A,int a,int b)
{
 for(int i=a-1;i<b-1;i++)
     printf("%d ",A[i]);
 printf("%d\n",A[b-1]);
}
   

int main()
{
 int a,b,n=0,l,x;
 char ch,r;
 int *arra,*arrb,*temp;
 FILE *in,*outs;
 in=fopen("input.txt","r");
 if(in==NULL)
  {
   printf("FILE  NOT FOUND\n");
   exit(0);
  }
 
 arra=(int*)malloc(sizeof(int));
 arrb=(int*)malloc(sizeof(int));

 fscanf(in,"%c ",&ch);
 while(1)
  {
   switch(ch)
    {
     case 'a': fscanf(in,"%c",&ch);n=0;
               if(ch=='(')
                {
                 fscanf(in,"%d%c",&l,&r);
                 while(r!=')')
                  {
                   n++;
                   temp=(int*) realloc(arra,n*sizeof(int));
                   arra=temp;
                   *(arra+n-1)=l;
                   fscanf(in,"%d%c",&l,&r);
                  }
                 n=n+1;
                  temp=(int*) realloc(arra,n*sizeof(int));
                   arra=temp;
                 *(arra+n-1)=l;
                 fscanf(in," %d\n",&x);
                }
               app(arra,x); break;
                 
     case 'c': fscanf(in,"%c",&ch);n=0;
               if(ch=='(')
                {
                 fscanf(in,"%d%c",&l,&r);
                 while(r!=')')
                  {
                   n=n+1;
                  temp=(int*) realloc(arra,n*sizeof(int));
                   arra=temp;
                   *(arra+n-1)=l;
                   fscanf(in,"%d%c",&l,&r);
                  }
                 n=n+1;
                 temp=(int*) realloc(arra,n*sizeof(int));
                   arra=temp;
                 *(arra+n-1)=l;
                }
               fscanf(in," %c",&ch);
               if(ch=='(')
                {
                 fscanf(in,"%d%c",&l,&r);
                 while(r!=')')
                  {
                   n=n+1;
                 temp=(int*) realloc(arra,n*sizeof(int));
                   arra=temp;
                   *(arra+n-1)=l;
                   fscanf(in,"%d%c",&l,&r);
                  }
                 n=n+1;
                  temp=(int*) realloc(arra,n*sizeof(int));
                   arra=temp;
                 *(arra+n-1)=l;
                 fscanf(in,"\n");
                }
               conc(arra,arra); break;
     case 'm': fscanf(in,"%c",&ch);n=0;
               if(ch=='(')
                {
                 fscanf(in,"%d%c",&l,&r);
                 while(r!=')')
                  {
                   n=n+1;
                 temp=(int*) realloc(arra,n*sizeof(int));
                   arra=temp;
                   *(arra+n-1)=l;
                   fscanf(in,"%d%c",&l,&r);
                  }
                 n=n+1;
                 arra=(int*) realloc(arra,n*sizeof(int));
                 *(arra+n-1)=l;
                 fscanf(in," %d\n",&x);
                }
               mem(arra,x); break;
     case 'l': fscanf(in,"%c",&ch);n=0;
               if(ch=='(')
                {
                 fscanf(in,"%d%c",&l,&r);
                 while(r!=')')
                  {
                   n=n+1;
                   arra=(int*) realloc(arra,n*sizeof(int));
                   *(arra+n-1)=l;
                   fscanf(in,"%d%c",&l,&r);
                  }
                 n=n+1;
                 arra=(int*) realloc(arra,n*sizeof(int));
                 *(arra+n-1)=l;
                 //fscanf(in," %d %d\n",a,b);
                }
               fscanf(in,"\n");
               len(arra); break;
     case 's': fscanf(in,"%c",&ch);n=0;
               if(ch=='(')
                {
                 fscanf(in,"%d%c",&l,&r);
                 while(r!=')')
                  {
                   n=n+1;
                   arra=(int*) realloc(arra,n*sizeof(int));
                   *(arra+n-1)=l;
                   fscanf(in,"%d%c",&l,&r);
                  }
                 n=n+1;
                 arra=(int*) realloc(arra,n*sizeof(int));
                 *(arra+n-1)=l;
                 fscanf(in," %d %d\n",&a,&b);
                }
               sli(arra,a,b); break;
     case 'x': exit(0); break;
    }
   fscanf(in,"%c ",&ch);
  }

 return 0;
}
