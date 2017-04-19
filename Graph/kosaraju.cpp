#include <bits/stdc++.h>

using namespace std;

int num_vertices;
int num_edges;
vector<vector<int> > adjList1, adjList2; // 1 = graph, 2 = reversed graph
vector<bool> visited;
vector<int> S;
int numSCC;

void dfs(int u, int mode) {
  visited[u] = true;
  vector<int> neighbours;
  if(mode == 1) neighbours = adjList1[u];
  else {
    neighbours = adjList2[u];
    cout << u << endl;
  }
  for(int neighbour : neighbours) {
    if(!visited[neighbour])
      dfs(neighbour, mode);
  }
  S.push_back(u);
}

int main() {

  cin >> num_vertices;
  cin >> num_edges;
  numSCC = 0;

  adjList1.assign(num_vertices, vector<int>());
  adjList2.assign(num_vertices, vector<int>());

  int a, b;
  for(int i = 0; i < num_edges; i++) {
    cin >> a >> b;
    adjList1[a].push_back(b);
    adjList2[b].push_back(a);
  }

  visited.assign(num_vertices, 0);
  for(int i = 0; i < num_vertices; i++) {
    if(!visited[i])
      dfs(i, 1);
    }

  visited.assign(num_vertices, 0);
  for(int i = num_vertices - 1; i >= 0; i--) {
    if(!visited[S[i]]) {
      numSCC++;
      cout << "SCC: " << numSCC << endl;
      dfs(S[i], 2);
    }
  }

  return 0;
}
