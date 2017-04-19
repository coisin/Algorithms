/*

Articulation Points And Bridges

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adjList;
vector<int> dfs_num, dfs_low, parent;
int dfs_counter;
int num_vertices;
int root, root_children;
bitset<40000> articulation;

int UNVISITED = 1e9;

int articulationPointsAndBridges(int u) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for(int i = 0; i < adjList[u].size(); i++) {
        int front = adjList[u][i];
        if(dfs_num[front] == UNVISITED) {
          parent[front] = u;
          if(u == root) root_children++;
          articulationPointsAndBridges(front);
          if(dfs_low[front] >= dfs_num[u])
            articulation[u] = true;
          if(dfs_low[front] > dfs_num[u])
            cout << "Bridge between " << u << " And " << front << endl;
          dfs_low[u] = min(dfs_low[u], dfs_low[front]);
        } else if(front != parent[u]) {
          dfs_low[u] = min(dfs_low[u], dfs_num[front]);
        }
    }
}

int main() {
    scanf("%d", &num_vertices);
    adjList.assign(num_vertices, vector<int>());

    int edge_count;
    scanf("%d", &edge_count);
    for (int i = 0; i < edge_count; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs_num.assign(num_vertices, UNVISITED);
    dfs_low.assign(num_vertices, 0);
    parent.assign(num_vertices, 0);

    dfs_counter = 0;

    for (int i = 0; i < num_vertices; i++)
        if (dfs_num[i] == UNVISITED) {
          root = i;
          root_children = 0;
          articulationPointsAndBridges(i);
          articulation[root] = root_children > 1;
        }

    for(int i = 0; i < num_vertices; i++) {
      if(articulation[i])
        cout << "Articulation Point at " << i << endl;
    }

    return 0;
}
