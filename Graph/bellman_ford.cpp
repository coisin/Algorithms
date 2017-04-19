#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<vector<pair<int, int> > > adjList; // {vertex, distance}
vector<int> dist;

void get_shortest_paths() {
  for(int k = 0; k < num_vertices - 1; k++) {
    for(int i = 0; i < num_vertices; i++) {
      for(int j = 0; j < adjList[i].size(); i++) {
        int v, d;
        v = adjList[i][j].first;
        d = adjList[i][j].second;
        dist[v] = min(dist[v], dist[i] + d);
      }
    }
  }
}

bool has_negative_cycle() {
  for(int i = 0; i < num_vertices; i++) {
    for(int j = 0; j < adjList[i].size(); i++) {
      int v, d;
      v = adjList[i][j].first;
      d = adjList[i][j].second;
      if(dist[v] > dist[i] + d) return true;
    }
  }
  return false;
}

int main() {

  return 0;
}
