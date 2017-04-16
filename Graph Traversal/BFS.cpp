#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<vector<int> > adjList;

void BFS(int source) {
  vector<bool> visited(num_vertices, false);
  queue<int> q;
  q.push(source);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if(visited[u]) continue;
    visited[u] = true;
    for(int v : adjList[u]) {
      q.push(v);
    }
  }
}

int main() {
  return 0;
}
