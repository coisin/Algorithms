#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
	int num_nodes;
	vector<int> parent, rank;
public:
	UnionFind(int _num_nodes):num_nodes(_num_nodes) {
		parent.assign(num_nodes, 0);
		rank.assign(num_nodes, 0);
		for(int i = 0; i < num_nodes; i++) parent[i] = i;
	}
	int findSet(int i) { return parent[i] == i ? i : (parent[i] = findSet(parent[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void merge(int i, int j) {
		int x = findSet(i);
		int y = findSet(j);
		if(x != y) {
			if(rank[x] > rank[y]) {
				parent[y] = x;
			} else {
				parent[x] = y;
				if(rank[x] == rank[y]) {
					rank[y]++;
				}
			}
		}
	}
};

int main() {}