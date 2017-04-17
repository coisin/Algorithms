#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<vector<int> > adjList;
vector<bool> visited;

void DFS(int u) {
  if(visited[u]) return;
  visited[u] = true;
  for(int v : adjList[u])
    DFS(v);
}

int main() {
  return 0;
}
