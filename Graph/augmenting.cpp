/*

Augmenting Paths Algorithm

*/

#include <bits/stdc++.h>

using namespace std;

int num_vertices;
int num_left_set; // Stores size of left set

/*
  This implementation expects nodes 0 - num_left_set to form the left side of the bipartite graph
*/

vector<int> visited, match;
vector<vector<int> > adjList;

int Aug(int u) {
  if(visited[u]) return 0;
  visited[u] = 1;
  for(int i = 0; i < adjList[u].size(); i++) {
    int front = adjList[u][i];
    if(match[front] == -1 || Aug(match[front])) {
      match[front] = u;
      return 1;
    }
  }
  return 0;
}

int main() {

  scanf("%d %d", &num_vertices, &num_left_set);
  adjList.assign(num_vertices, vector<int>() );
  int a, b;
  scanf("%d %d", &a, &b);
  while(a != -1 && b != -1) {
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    scanf("%d %d", &a, &b);
  }
  match.assign(num_vertices, -1);
  int max_matchings = 0;
  for(int i = 0; i < num_left_set; i++) {
    visited.assign(num_vertices, 0);
    max_matchings += Aug(i);
  }
  printf("%d", max_matchings);

  return 0;
}
