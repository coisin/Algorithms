#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > ar;

void read_in() {
	int rows, columns;
	cin >> rows >> columns;
	ar.assign(rows, vector<int>(columns));
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cin >> ar[i][j];
			if(i > 0) ar[i][j] += ar[i - 1][j];
			if(j > 0) ar[i][j] += ar[i][j - 1];
			if(i > 0 && j > 0) ar[i][j] -= ar[i - 1][j - 1];
		}
	}
}

int range_sum(int x1, int y1, int x2, int y2) {
	int answer = ar[y2][x2];
	if(x1 > 0) answer -= ar[y1][x1 - 1];
	if(y1 > 0) answer -= ar[y1 - 1][x1];
	if(x1 > 0 && y1 > 0) answer += ar[y1 - 1][x1 - 1];
	return answer;
}

int main() {
	
}
