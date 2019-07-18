#include <stdio.h> 

int V,E;

int findmin(int dist[], int set[]) 
{ 
int min = 999999, min_index; 

for (int v = 0; v < V; v++) 
	if (set[v] == 0 && dist[v] <= min) 
		min = dist[v], min_index = v; 

return min_index; 
} 


int print(int dist[], int n) 
{
  FILE *out=fopen("output.txt","w");
for (int i = 0; i < V; i++) 
	fprintf(out,"%d %d\n", i, dist[i]);
  fclose(out); 
  return 0;
} 


void djikshtra(int graph[V][V], int src) 
{ 
	int dist[V];	 

	int set[V]; 


	for (int i = 0; i < V; i++) 
		dist[i] = 999999, set[i] = 0; 


	dist[src] = 0; 


	for (int count = 0; count < V-1; count++) 
	{ 
	 
	int u = findmin(dist, set); 


	set[u] = 1; 


	for (int v = 0; v < V; v++) 
 
		if (!set[v] && graph[u][v] && dist[u] != 999999 
									&& dist[u]+graph[u][v] < dist[v]) 
			dist[v] = dist[u] + graph[u][v]; 
	} 

	print(dist, V); 
} 


int main() 
{ 
  int a,b,c;
  FILE *in=fopen("input.txt","r");
  fscanf(in,"%d",&V);
  int graph[V][V];

  fscanf(in,"%d",&E);
  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
      graph[i][j]=0;
    }
  }
  
  for (int i=0;i<E;i++)
  {
    fscanf(in,"%d%d%d",&a,&b,&c);
    graph[a][b]=c;
  }
  fscanf(in,"%d",&a);

djikshtra(graph, a); 
  fclose(in);
	return 0; 
} 
