#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<vector<pair<int, int> > > adjList; // {vertex, distance}
vector<int> dist;

void dijkstra(int source) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  dist[source] = 0;
  pq.push({ source, 0 }); // { vertex, distance }

  while(!pq.empty()) {
    int u, d;
    u = pq.top().first;
    d = pq.top().second;
    pq.pop();
    if(d > dist[u]) continue; // Old Entry
    for(int i = 0; i < adjList[u].size(); i++) {
      int v, l;
      v = adjList[u][i].first;
      l = adjList[u][i].second;
      if(dist[v] > dist[u] + l) {
        dist[v] = dist[u] + l;
        pq.push({ v, dist[v] });
      }
    }
  }
}

int main() {

  return 0;
}
