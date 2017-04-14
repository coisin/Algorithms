
/*

Kruskal's Algorithm For Finding Minimum Spanning Tree

*/

#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
  vector<int> rank, p;
public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    for(int i = 0; i < n; i++) p[i] = i;
  }
  int findSet(int i) {
    return p[i] == i ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void mergeSet(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if(rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if(rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }
};

int num_vertices, num_edges;
vector<pair<int, pair<int, int> > > edges; // {Weight, {Node_A, Node_B} }

int main() {

  scanf("%d %d", &num_vertices, &num_edges);
  for(int i = 0; i < num_edges; i++) {
    int w, a, b;
    scanf("%d %d %d", &a, &b, &w);
    edges.push_back({w, {a, b}});
  }

  UnionFind uf(num_vertices);
  sort(edges.begin(), edges.end());

  int mst = 0;
  for(int i = 0; i < edges.size(); i++) {
    int w, a, b;
    w = edges[i].first;
    a = edges[i].second.first;
    b = edges[i].second.second;
    if(!uf.isSameSet(a, b)) {
      uf.mergeSet(a, b);
      mst += w;
    }
  }

  printf("%d", mst);

  return 0;
}
