/*

Tarjan's Algorithm for finding Strongly Connected Components

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adjList;
vector<int> dfs_num, dfs_low, parent;
stack<int> s;
int dfs_counter;
int num_vertices;
int root;
int root_children;

int UNVISITED = 1e9;

int tarjan(int u) {
  dfs_num[u] = dfs_low[u] = dfs_counter++;
  s.push(u);
  for(int i = 0; i < adjList[u].size(); i++) {
    int front = adjList[u][i];
    if(dfs_num[front] == UNVISITED) {
      if(u == root) {
        root_children++;
      }
      parent[front] = u;
      tarjan(front);
      dfs_low[u] = min(dfs_low[u], dfs_low[front]);
    } else if(front != parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[front]);
    }
  }
  if(dfs_num[u] == dfs_low[u]) {
    cout << "----- Start -----" << endl;
    while(true) {
      int top = s.top();
      s.pop();
      cout << top << " ";
      if(top == u) break;
    }
    cout << endl;
  }
}

int main() {
  scanf("%d", &num_vertices);
  adjList.assign(num_vertices, vector<int>());

  int edge_count;
  scanf("%d", &edge_count);
  for(int i = 0; i < edge_count; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  dfs_num.assign(num_vertices, UNVISITED);
  dfs_low.assign(num_vertices, 0);
  parent.assign(num_vertices, 0);

  for(int i = 0; i < num_vertices; i++) {
    if(dfs_num[i] == UNVISITED) {
      root = i;
      root_children = 0;
      tarjan(i);
    }
  }

  return 0;
}
