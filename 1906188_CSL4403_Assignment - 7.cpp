// Dijkstra's Algorithm (Single Source Shortest path)
//Digvijay Srivastava 1906188

#include <stdio.h>
#define SIZE 20
#define INFINITY 99999

void Dijkstra(int Graph[SIZE][SIZE], int n, int start) {
  int cost[SIZE][SIZE], distance[SIZE], pred[SIZE];
  int visited[SIZE], count, minDistance, nextnode, i, j;

  //Distance Matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    minDistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < minDistance && !visited[i]) {
        minDistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (minDistance + cost[nextnode][i] < distance[i]) {
          distance[i] = minDistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }
  
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source (Vertex 0) to Vertex %d is: %d", i, distance[i]);
    }
}
int main() {
  int Graph[SIZE][SIZE], i, j, n, u;
  printf("\n Enter the number of vertices : ");
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        {
        printf("Graph[%d][%d] = ",i,j);
        scanf("%d",&Graph[i][j]);
        }
    
  u = 0;
  Dijkstra(Graph, n, u);

  return 0;
}

