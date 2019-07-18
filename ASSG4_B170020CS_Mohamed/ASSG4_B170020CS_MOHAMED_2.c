#include <stdio.h> 
#include<stdlib.h>

int V,E;
FILE *out;

int min(int dist[], int set[]) 
{ 
int min = 999999, min_index; 

for (int v = 0; v < V; v++) 
	if (set[v] == 0 && dist[v] <= min) 
		min = dist[v], min_index = v; 

return min_index; 
} 

int print(int dist[], int n,FILE* out) 
{
  int i;

for ( i = 0; i < V-1; i++) 
	fprintf(out,"%d ",dist[i]);

   fprintf(out,"%d\n",dist[i]);

  return 0;
} 

int print1(int dist[],int dest,FILE* out) 
{
  
    fprintf(out,"%d\n", dist[dest]);
  
  return 0;
} 

void djikshtra1(int graph[V][V], int src,int dest,FILE* out) 
{ 
	int dist[V];	 

	int set[V]; 


	for (int i = 0; i < V; i++) 
		dist[i] = 999999, set[i] = 0; 


	dist[src] = 0; 


	for (int count = 0; count < V-1; count++) 
	{ 
	 
	int u = min(dist, set); 


	set[u] = 1; 


	for (int v = 0; v < V; v++) 
 
		if (!set[v] && graph[u][v] && dist[u] != 999999 
									&& dist[u]+graph[u][v] < dist[v]) 
			dist[v] = dist[u] + graph[u][v]; 
	} 

	print1(dist,dest,out); 
} 




void djikshtra(int graph[V][V], int src,FILE* out) 
{ 
	int dist[V];	 

	int set[V]; 


	for (int i = 0; i < V; i++) 
		dist[i] = 999999, set[i] = 0; 


	dist[src] = 0; 


	for (int count = 0; count < V-1; count++) 
	{ 
	 
	int u = min(dist, set); 


	set[u] = 1; 


	for (int v = 0; v < V; v++) 
 
		if (!set[v] && graph[u][v] && dist[u] != 999999 
									&& dist[u]+graph[u][v] < dist[v]) 
			dist[v] = dist[u] + graph[u][v]; 
	} 

	print(dist, V,out); 
} 



int main() 
{ 
  int a,b,c,temp,temp2=0,l=1;
  int i,j,k;
  FILE *in=fopen("input.txt","r");
  FILE *in2=fopen("input.txt","r");
  FILE *out=fopen("output.txt","w");

  fscanf(in,"%d\n",&V);
  char ch,ch2;
  int graph[V][V];
  char ignore[1024];



  for(i=0;i<V;i++)
  {
    for(j=0;j<V;j++)
    {
      graph[i][j]=0;
    }
  }

i=0;
j=0;

      for(int i=0;i<V;i++)
    {
      printf("\nhere in");
       temp=0;
       in2=fopen("input.txt","r");

         for (int k = 0 ; k < (V+1+i) ; k++)
            fgets(ignore,1023,in2);
        k=0;
            
        j=1;

       ch=fgetc(in);
       ch2=fgetc(in2);

       while(ch!='\n')
       {
             
          if(ch==' ')
          {
              graph[i][temp]=0;
             printf("1-%d",temp);

                       while(ch2!='\n')
                        {
             
                             if(ch2==' ')
                                 {
                                     graph[i][temp]=temp2;
                                     printf("2-%d",temp2);

                                     temp2=0;
                                      l=1;
                                      ch2=fgetc(in2);
                                      break;
                                 }
                             else
                                 {
                                      temp2=l*temp2+(ch2-'0');
                                       l*=10;
                                 }
                                    ch2=fgetc(in2);
                          }

              temp=0;
              j=1;
          }
          else
          {
              temp=j*temp+(ch-'0');
              j*=10;
          }
          ch=fgetc(in);
       }

                 while(1)
                        {

                         graph[i][temp]=0;
                         printf("\n1-%d",temp);

                             if(ch2=='\n')
                                 {
                                     graph[i][temp]=temp2;
                                     printf("\n\n2-%d ",temp2);

                                     temp2=0;
                                      l=1;
                                      break;
                                 }
                             else
                                 {
                                      temp2=l*temp2+(ch2-'0');
                                       l*=10;
                                 }
                                    ch2=fgetc(in2);
                          }

   }


printf("\nhere");
 
  while(!feof(in2))
  {
    ch=fgetc(in2);
    //printf("\nch=%c",ch);
    if(ch=='a')
      {
        fscanf(in2,"psp %d\n",&a);
        //printf("\na=%d",a);
        djikshtra(graph,a,out);
      }
    else
    {
	ch=fgetc(in2);
	    if(ch=='t')
	    exit(0);
	else
	{
      fscanf(in2,"sp %d %d\n",&a,&b);
      //printf("\na=%d,b=%d",a,b);
      djikshtra1(graph,a,b,out);
	}
    }
  }
    
	return 0; 
} 
