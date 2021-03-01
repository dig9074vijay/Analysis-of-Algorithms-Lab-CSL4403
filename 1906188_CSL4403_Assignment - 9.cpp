
//Bellman-Ford's single source shortest path algorithm
//Digvijay Srivastava (1906188)
#include <bits/stdc++.h> 
using namespace std;
struct Graph { 
	int V, E; 
	struct Edge* edge; 
}; 

struct Edge { 
	int src, dest, weight; 
}; 

// Function to create a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->E = E; 
	graph->V = V; 
	graph->edge = new Edge[E]; 
	return graph; 
} 

void printDist(int dist[], int n) 
{ 
	printf("Vertex     Distance\n"); 
	for (int i = 0; i < n; ++i) 
		printf("%d \t %d\n", i, dist[i]); 
} 


void BellmanFord(struct Graph* graph, int src) 
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
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
			printf("\nGraph contains negative weight cycle"); 
			return; 
		} 
	} 
	printDist(dist, V); 
	return; 
} 

int main() 
{ 
	int V; // Vertices 
	int E; // Edges
	int SRC; //Source
	cout<<"\nEnter the number of vertices in the Graph : ";
	cin>>V;
	cout<<"\nEnter the number of edges in the Graph : ";
	cin>>E;
	struct Graph* graph = createGraph(V, E); 
    cout<<"\nEnter the edges in the Directed Graph : "<<endl;
    for(int i = 0; i < E; i++ )
    {
        cout<<"\nEnter the source Vertex of edge "<< i <<" : ";
        cin>>graph->edge[i].src;
        cout<<"Enter the destination Vertex of edge "<< i <<" : ";
	    cin>>graph->edge[i].dest;
	    cout<<"Enter the weight of edge "<< i <<" : ";
	    cin>>graph->edge[i].weight; 

    }
    cout<<"\nEnter the Source vertex:";
    cin>>SRC;
	BellmanFord(graph, SRC); 

	return 0; 
} 



