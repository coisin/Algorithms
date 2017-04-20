#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<vector<pair<int, int> > > adjList; // {vertex, distance}
vector<int> dist;

void dijkstra(int source) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  dist[source] = 0;
  pq.push({ 0, source }); // { distance vertevertex }

  while(!pq.empty()) {
    int u, d;
    u = pq.top().second;
    d = pq.top().first;
    pq.pop();
    if(d > dist[u]) continue; // Old Entry
    for(int i = 0; i < adjList[u].size(); i++) {
      int v, l;
      v = adjList[u][i].first;
      l = adjList[u][i].second;
      if(dist[v] > dist[u] + l) {
        dist[v] = dist[u] + l;
        pq.push({ dist[v], v });
      }
    }
  }
}

int main() {

  return 0;
}
