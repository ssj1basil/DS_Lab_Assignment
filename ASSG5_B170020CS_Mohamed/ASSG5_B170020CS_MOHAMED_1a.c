#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
FILE* out;
int V;
struct Edge 
{ 
    int src, dest, weight; 
}; 
 
struct Graph 
{ 
    int V, E; 
   
    struct Edge* edge; 
}; 
  
struct Graph* create(int V, int E) 
{ 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
    graph->V = V; 
    graph->E = E; 
  
    graph->edge = (struct Edge*)malloc(sizeof(struct Edge)*E); 
  
    return graph; z
} 
  
struct subset 
{ 
    int parent; 
    int rank; 
}; 
  
int find(struct subset subsets[], int i) 
{ 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
  
    return subsets[i].parent; 
}

void Union(struct subset subsets[], int x, int y) 
{ 
    int root_a = find(subsets, x); 
    int root_b = find(subsets, y); 
   
    if (subsets[root_a].rank < subsets[root_b].rank) 
        subsets[root_a].parent = root_b; 
    else if (subsets[root_a].rank > subsets[root_b].rank) 
        subsets[root_b].parent = root_a; 
  
    else
    { 
        subsets[root_b].parent = root_a; 
        subsets[root_a].rank++; 
    } 
} 
  
int myComp(const void* a, const void* b) 
{ 
    struct Edge* a1 = (struct Edge*)a; 
    struct Edge* b1 = (struct Edge*)b; 
    return a1->weight > b1->weight; 
} 
  
void kruskal(struct Graph* graph,FILE* out) 
{ 
    int count=0;
    int V = graph->V; 
    struct Edge result[V];  
    int e = 0; 
    int i = 0;  
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 
  
    struct subset *subsets = 
        (struct subset*) malloc( V * sizeof(struct subset) ); 
  
    for (int v = 0; v < V; ++v) 
    { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
  
    while (e < V - 1) 
    { 
    
        struct Edge next_edge = graph->edge[i++]; 
  
        int x = find(subsets, next_edge.src); 
        int y = find(subsets, next_edge.dest); 
  
        if (x != y) 
        { 
            result[e++] = next_edge; 
            Union(subsets, x, y); 
        } 
     
    } 
  
    for (i = 0; i < e; ++i) 
     count+=result[i].weight;

     fprintf(out,"%d",count);
    return; 
} 
  
struct Graph* addedge(struct Graph* graph,int src,int weight,int dest,int i)
{

    graph->edge[i].src = src; 
    graph->edge[i].dest = dest; 
    graph->edge[i].weight = weight;

    return graph;
}
int main() 
{ 

    int i=0,k=0,count=0,l=1;
    int j=0,temp=0,temp2=0;
    FILE* in=fopen("input.txt","r");
    FILE* in2=fopen("input.txt","r");
    out=fopen("output.txt","w");
    char ch,ch2,ignore[1024];

    fscanf(in,"%d\n",&V);
    struct Graph* graph = create(V, V*V); 




    
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
        //     printf("1-%d",temp);

                       while(ch2!='\n')
                        {
             
                             if(ch2==' ')
                                 {
                                    graph=addedge(graph,i,temp2,temp,count);
                                    count++;
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
                        // printf("\n1-%d",temp);

                             if(ch2=='\n')
                                 {
                                     graph=addedge(graph,i,temp2,temp,count);
                                    count++;
                               //      printf("\n\n2-%d ",temp2);
                                    count++;
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
    kruskal(graph,out); 
  
    return 0; 
} 
