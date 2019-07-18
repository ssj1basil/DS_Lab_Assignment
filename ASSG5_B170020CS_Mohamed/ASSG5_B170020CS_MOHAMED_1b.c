#include <stdio.h> 
#include <limits.h> 
#include<stdbool.h> 
  FILE* out;
  int V;

int findmin(int key[], bool mstSet[]) 
{ 
 
int min = INT_MAX, min_index; 
  
for (int v = 0; v < V; v++) 
    if (mstSet[v] == false && key[v] < min) 
        min = key[v], min_index = v; 
  
return min_index; 

} 
  

int print(int parent[], int n, int graph[V][V],FILE* out) 
{ 
    int sum=0;

for (int i = 1; i < V; i++) 
    sum+=graph[i][parent[i]]; 
fprintf(out,"%d",sum);

} 
  

void prims(int graph[V][V],FILE* out) 
{ 
    int v;
    int parent[V];  
    int key[V];  
    bool mstSet[V];  
  
    for (int i = 0; i < V; i++) 
        key[i] = 9999, mstSet[i] = false; 
  
    
    key[0] = 0;      
    parent[0] = -1; 
    for (int count = 0; count < V-1; count++) 
    { 
        
        int u = findmin(key, mstSet); 
      
        mstSet[u] = true; 
  
      
        for ( v = 0; v < V; v++) 
  
        if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
            
            parent[v] = u, key[v] = graph[u][v];

    
    } 
  
    print(parent, V, graph,out); 
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
     // printf("\nhere in");
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
        //     printf("1-%d",temp);

                       while(ch2!='\n')
                        {
             
                             if(ch2==' ')
                                 {
                                     graph[i][temp]=temp2;
                               //     printf("2-%d",temp2);

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
                           // printf("\nc=%c",ch2);
                         graph[i][temp]=0;
                        // printf("\n1-%d",temp);

                             if(ch2=='\n')
                                 {
                                     graph[i][temp]=temp2;
                               //      printf("\n\n2-%d ",temp2);

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

  /*  for(i=0;i<V;i++)
    {
        printf("\n");
        for(j=0;j<V;j++)
        printf("%d ",graph[i][j]);
    }*/

  prims(graph,out);
  
    return 0; 
} 
