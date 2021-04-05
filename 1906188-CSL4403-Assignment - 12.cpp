//Program to find Hamiltonian Cycles in a graph
//Digvijay Srivastava (1906188)
#include <bits/stdc++.h>
using namespace std;

#define N 1000
int V;
bool graph[N][N];


void displaySolution(int path[]);

bool isPossible(int v, bool graph[N][N],int path[], int pos)
{
  if (graph [path[pos - 1]][ v ] == 0)
    return false;

  for (int i = 0; i < pos; i++)
    if (path[i] == v)
      return false;

  return true;
}

bool hamCycle(bool graph[N][N],int path[], int pos)
{
 
  if (pos == V)
  {
    if (graph[path[pos - 1]][path[0]] == 1)
      return true;
    else
      return false;
  }

  for (int v = 1; v < V; v++)
  {
    if (isPossible(v, graph, path, pos))
    {
      path[pos] = v;
      if (hamCycle (graph, path, pos + 1) == true)
        return true;
      path[pos] = -1;
    }
  }
  return false;
}

bool HamiltonianCycle(bool graph[N][N])
{
  int *path = new int[V];
  for (int i = 0; i < V; i++)
    path[i] = -1;
  path[0] = 0;
  if (hamCycle(graph, path, 1) == false )
  {
    cout << "\nSolution does not exist";
    return false;
  }

  displaySolution(path);
  return true;
}

void displaySolution(int path[])
{
  cout << "Solution Exists:"
      " Following is one Hamiltonian Cycle \n";
  for (int i = 0; i < V; i++)
    cout << path[i] << " ";
  cout << path[0] << " ";
  cout << endl;
}

int main()
{
  printf("Enter the number of Vertices : ");
  scanf("%d",&V);
  printf("\nEnter the Adjacency Matrix of the graph : \n");
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      cin>>graph[i][j];
    }
  }
  HamiltonianCycle(graph); 
  return 0;
}
