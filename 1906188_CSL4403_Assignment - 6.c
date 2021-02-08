// Prim's Algorithm in C
// Digvijay Srivastava (1906188)
#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999

// number of vertices in graph
#define V 7

//Adjacency matrix to represent the graph
int G[V][V] = {
  {0, 28, 0, 0, 0, 10, 0},
  {28, 0, 16, 0, 0, 0, 14},
  {0, 16, 0, 12, 0, 0, 0},
  {0, 0, 12, 0, 22, 0, 18},
  {0, 0, 0, 22, 0, 25, 24},
  {10, 0, 0, 0, 25, 0, 0},
  {0, 14, 0, 18, 24, 0, 0}
};

int main() {
  int selectedEdge, minWeight = 0; 

  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[V];
  
  // set selected false initially
  for(int i=0;i<7;i++)
    selected[i] = false;
  
  // set number of edge to 0
  selectedEdge = 0;
  
  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  
  printf("The edges with the corresponding cost are as follows:\n");
  printf("Edge : Cost\n");

  while (selectedEdge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    minWeight += G[x][y];
    selected[y] = true;
    selectedEdge++;
  }
  printf("Total cost of the given MST is : %d",minWeight);
  return 0;
}
