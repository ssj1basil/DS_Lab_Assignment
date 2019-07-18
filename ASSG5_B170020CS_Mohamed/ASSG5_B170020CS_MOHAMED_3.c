
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
  
typedef struct Edge { 
    int src, dest, weight; 
}Edge; 
  
typedef struct Graph { 
    int V, E; 
    struct Edge* edge; 
}Graph; 
  
struct Graph* createGraph(int V, int E) 
{ 
    struct Graph* graph = (Graph*)malloc(sizeof(Graph)); 
    graph->V = V; 
    graph->E = E; 
    graph->edge = (Edge*)malloc(sizeof(Edge)*E); 
    return graph; 
} 
   
int isneg(struct Graph* graph, 
                           int src) 
{ 
    int V = graph->V; 
    int E = graph->E; 
    int dist[V]; 
  
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX; 
    dist[src] = 0; 
 
    for (int i = 1; i <= V - 1; i++) { 
        for (int j = 0; j < E; j++) { 
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 
   
    for (int i = 0; i < E; i++) { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            return 1; 
    } 
  
    return 0; 
} 
  
 Graph* addedge(int i,int src,int dest,int weight, Graph* graph)
{
    graph->edge[i].src = 0; 
    graph->edge[i].dest = 1; 
    graph->edge[i].weight = -1; 

    return graph;

}
// Driver program to test above functions 
int main() 
{
    FILE *in,*out;
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
     
    int V,E,i,weight;


    fscanf(in,"%d %d",&V,&E);

    Graph* graph = createGraph(V, E); 
   
    for(i=0;i<E;i++)
    {
        fscanf(in,"%d %d %d",&V,&E,&weight);
        graph=addedge(i,V,E,weight,graph);
    
    }
  
    if (isneg(graph, 0)) 
        fprintf(out,"1\n");
    else
    {
        fprintf(out,"1");
    }
    
  
    return 0; 
} 
