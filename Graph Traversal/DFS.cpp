#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<vector<int> > adjList;

void DFS(int u) {
  if(visited[u]) return;
  visited[u] = true;
  for(int v : adjList[v])
    DFS(v);
}

int main() {
  return 0;
}
