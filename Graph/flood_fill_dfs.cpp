#include <bits/stdc++.h>

using namespace std;

char grid[50][50];
int num_rows, num_columns;

int change_x[] = {1, 0, -1, 0};
int change_y[] = {0, 1, 0, -1};

int flood_fill(int row, int column, char from_paint, char to_paint) {
	if(row < 0 || row >= num_rows || column < 0 || column >= num_columns) return 0;
	if(grid[row][column] != from_paint) return 0;
	grid[row][column] = to_paint;
	int num_cells_painted = 1;
	for(int i = 0; i < 4; i++) {
		int new_row = row + change_y[i];
		int new_column = column + change_x[i];
		num_cells_painted += flood_fill(new_row, new_column, from_paint, to_paint);
	}
	return num_cells_painted;
}

int main() {}