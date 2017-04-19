#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int> > adjList;

vector<int> topological_sort;

void dfs(int u) {
  if(visited[u]) return;
  visited[u] = true;
  for(int a : adjList[u])
    dfs(a);
  topological_sort.push_back(u);
}

int main() {}
