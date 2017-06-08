#include <bits/stdc++.h>

using namespace std;

class fenwick {
private:
	vector<int> ft;
public:
	fenwick(int n) {
		ft.assign(n + 1, 0);
	}
	void update(int k, int v) {
		for(; k < ft.size(); k += LSOne(k)) ft[k] += v;
	}
	int rsq(int k) {
		int answer = 0;
		for(; k; k -= LSOne(k)) answer += ft[k];
		return answer;
	}
	int LSOne(int k) { return k & (-k); }
};

int main() {
	fenwick ft(10);
	ft.update(5, 1);
	ft.update(2, 4);
	ft.update(6, 3);
	ft.update(1, 1);
	ft.update(9, -5);
	ft.update(5, 3);
	for(int i = 0; i < 10; i++) {
		cout << ft.rsq(i) << " ";
	}
}