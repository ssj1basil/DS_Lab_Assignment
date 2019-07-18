#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int search(char p[], char t[], int q,int d,FILE* out) 
{	
    int psize = strlen(p); 
    int tsize = strlen(t); 
    int i, j,s=0,l=0,h=1;
  
    for (i = 0; i < psize-1; i++) 
        h = (h*d)%q; 
  

    for (i = 0; i < psize; i++) 
    { 
        s = (d*s + p[i])%q; 
        l = (d*l + t[i])%q; 
    } 
  
    for (i = 0; i <= tsize - psize; i++) 
    { 
  
        if ( s == l ) 
        { 
            for (j = 0; j < psize ; j++) 
            { 
                if (t[i+j] != p[j]) 
                    break; 
            } 
   
            if (j == psize) 
                fprintf(out,"%d ",i);
        } 
  
        if ( i < tsize - psize ) 
        { 
            l = (d*(l - t[i]*h) + t[i+psize])%q; 
 
            if (l < 0) 
            l = (l + q); 
        } 
	}
} 


int main()
{

FILE* in;
FILE* out;
in=fopen("input.txt","r");
out=fopen("output.txt","w");
out=fopen("output.txt","a");

int q=101,i=0,j=0,d=256;
char ch[100],t[100],p[100];

while(fgets(ch,99,in)!=NULL)
{

	switch(ch[0])
	{
		case't':printf("\nin t");
				for(i=0;ch[i]!='"'&&ch[i]!='\n';i++)
				
				for(j=0;ch[i]!='\n'&&ch[i]!='"';i++,j++)
					t[j]=ch[i];

				t[j]='\0';
				printf("%s",t);
				break;

		case'p':printf("\nin p");
				if(ch[1]=='r')
				{
				search(p,t,q,out,d);
				fprintf(out,"\n");
				}
				else
				{	
				for(i=0;ch[i]!='"'&&ch[i]!='\n';i++)
				
				for(j=0;ch[i]!='\n'&&ch[i]!='"';i++,j++)
					p[j]=ch[i];

				p[j]='\0';

				printf("%s",p);
				}
				break;

		case'e':exit(0);

		default:printf("\nNot a proper character");
				break;
	
	};


}

return 0;
}
