#include <bits/stdc++.h>

using namespace std;

vector<int> ar;

int range_sum(int i, int j) {
	int answer = ar[j];
	if(i > 0) answer -= ar[i - 1];
	return answer;
}

int main() {
	int num_vertices;
	cin >> num_vertices;
	for(int i = 0; i < num_vertices; i++) {
		cin >> ar[i];
		if(i > 0) ar[i] += ar[i - 1];
	}
}
