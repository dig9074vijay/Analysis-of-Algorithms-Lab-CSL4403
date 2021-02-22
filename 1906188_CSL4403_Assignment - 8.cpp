// C++ Program for Floyd Warshall Algorithm 
// Digvijay Srivastava (1906188)
#include <bits/stdc++.h>
using namespace std;
 
#define V 4 

#define INF 99999 
 
void displayDistanceMatrix(int dist[][V]); 
 
//Function to implement all pairs shortest path Algorithm
void floyd (int graph[][V]) 
{ 
  
    int dist[V][V], i, j, k; 
 
    
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
 
   
    for (k = 0; k < V; k++) 
    { 
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
 
    // Display the shortest distance matrix 
    displayDistanceMatrix(dist); 
} 
 

void displayDistanceMatrix(int dist[][V]) 
{ 
    cout<<"\nThe final distance matrix with shortest distance "
            "between every pair of vertices : \n"; 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INF) 
                cout<<"INF"<<"     "; 
            else
                cout<<dist[i][j]<<"     "; 
        } 
        cout<<endl; 
    } 
} 
 
int main() 
{ 
    int Graph[V][V], n, i, j;
  /*int graph[V][V] = { {0, 3, INF, 7}, 
                        {8, 0, 2, INF}, 
                        {5, INF, 0, 1}, 
                        {2, INF, INF, 0} 
                    }; */
                    
  printf("\nEnter the number of vertices : ");
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        {
        printf("Graph[%d][%d] = ",i,j);
        scanf("%d",&Graph[i][j]);
        }          
    floyd(Graph); 
    return 0; 
} 
 

