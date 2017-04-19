#include <bits/stdc++.h>

using namespace std;

int num_vertices;
vector<bool> visited;
vector<vector<int> > adjList;

vector<int> topological_sort;

void kahns(int u) {
  vector<int> degree(num_vertices, 0);
  queue<int> q;
  for(int i = 0; i < num_vertices; i++)
  	for(int n : adjList[i])
  		degree[n]++;
  for(int i = 0; i < num_vertices; i++)
  	if(degree[i] == 0)
  		q.push(i);
  while(!q.empty()) {
  	int u = q.front();
  	q.pop();
  	topological_sort.push_back(u);
  	for(int n : adjList[u]) {
  		degree[n]--;
  		if(degree[n] == 0)
  			q.push(n);
  	}
  }
}

int main() {}
