#include <bits/stdc++.h>

using namespace std;

string a, b;
int dp[100][100];

int edit_distance(int i, int j) {
	if(dp[i][j] != -1) return dp[i][j];
	if(i == 0) return j;
	if(j == 0) return i;
	if(a[i - 1] == b[j - 1]) return edit_distance(i - 1, j - 1);
	return dp[i][j] = 1 + min(edit_distance(i - 1, j - 1), min(edit_distance(i, j - 1), edit_distance(i - 1, j)));
}

int main() {}
