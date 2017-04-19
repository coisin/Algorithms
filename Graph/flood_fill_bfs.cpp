#include <bits/stdc++.h>

using namespace std;

int num_rows, num_columns;
char grid[50][50];

int change_x[] = {1, 0, -1, 0};
int change_y[] = {0, 1, 0, -1};

void flood_fill(char painted_from, char painted_to) {
	queue<pair<int, int> > q;
	q.push({0, 0});
	while(!q.empty()) {
		int row = q.front().first;
		int column = q.front().second;
		q.pop();
		grid[row][column] = painted_to;
		for(int i = 0; i < 4; i++) {
			int new_row = row + change_y[i];
			int new_column = column + change_x[i];
			if(new_row < 0 || new_row >= num_rows || new_column < 0 || new_column >= num_columns) continue;
			if(grid[new_row][new_column] != painted_from) continue;
			q.push({new_row, new_column});
		}
	}
}

int main() {}