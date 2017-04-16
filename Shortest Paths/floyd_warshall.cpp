#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<vector<int> > adjMatrix; // num_vertices * num_vertices - Initial Values = 100000000 or weight between 2 vertices
vector<vector<int> > connected; // num_vertices * num_vertices - Initial Values = false or true if 2 vertices are connected directly

void floyd_warshall() {
  for(int i = 0; i < num_vertices; i++)
    for(int j = 0; j < num_vertices; j++)
      for(int k = 0; k < num_vertices; k++)
        adjMatrix[j][k] = min(adjMatrix[j][k], adjMatrix[j][i] + adjMatrix[i][k]);
}

void transitive_closure() {
  for(int i = 0; i < num_vertices; i++)
    for(int j = 0; j < num_vertices; j++)
      for(int k = 0; k < num_vertices; k++)
        connected[j][k] |= (connected[j][i] & connected[i][k]);
}

int main() {

  return 0;
}
