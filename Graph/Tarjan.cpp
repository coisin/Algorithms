/*

Tarjan's Algorithm for finding Strongly Connected Components

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adjList;
vector<int> dfs_num, dfs_low, visited;
vector<int> s;
int dfs_counter;
int num_vertices;

int UNVISITED = 1e9;

int tarjan(int u) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    visited[u] = true;
    s.push_back(u);
    for(int i = 0; i < adjList[u].size(); i++) {
        int front = adjList[u][i];
        if(dfs_num[front] == UNVISITED)
            tarjan(front);
        if(visited[front])
            dfs_low[u] = min(dfs_low[u], dfs_low[front]);
    }
    if(dfs_num[u] == dfs_low[u]) {
        cout << "----- Start -----" << endl;
        while(true) {
            int top = s.back();
            s.pop_back();
            visited[top] = false;
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
    for (int i = 0; i < edge_count; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adjList[a].push_back(b);
    }

    dfs_num.assign(num_vertices, UNVISITED);
    dfs_low.assign(num_vertices, 0);
    visited.assign(num_vertices, 0);

    dfs_counter = 0;

    for (int i = 0; i < num_vertices; i++)
        if (dfs_num[i] == UNVISITED) tarjan(i);

    return 0;
}
