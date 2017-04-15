#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
  vector<int> st;
  vector<int> A;
  int _n;
public:
  int left(int i) { return i << 1; }
  int right(int i) { return (i << 1) + 1; }
  int operation(int i, int j) {
    return A[i] < A[j] ? i : j;
  }
  int mrq(int p, int L, int R, int i, int j) {
    if(L > j || R < i) return -1;
    if(L >= i && R <= j) return st[p];
    int leftSeg = mrq(left(p), L, (L + R) / 2, i, j);
    int rightSeg = mrq(right(p), (L + R) / 2 + 1, R, i, j);
    if(leftSeg == -1) return rightSeg;
    if(rightSeg == -1) return leftSeg;
    return operation(leftSeg, rightSeg);
  }
  int mrq(int i, int j) {
    return mrq(1, 0, _n, i, j);
  }
  void build(int p, int L, int R) {
    if(L == R) {
      st[p] = L;
      return;
    }
    build(left(p), L, (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R);
    st[p] = operation(st[left(p)], st[right(p)]);
  }
  SegmentTree(int n, vector<int> _A) {
    st.assign(4 * n, 0);
    _n = n;
    A = _A;
    build(1, 0, n);
  }
};

int main() {

  int _A[] = {1, 7, 3, 87, 34, 6, 42,2, 43, -5};
  vector<int> A(_A, _A + 10);

  SegmentTree st(10, A);

  cout << st.mrq(3, 5) << endl;
  cout << st.mrq(5, 6) << endl;
  cout << st.mrq(5, 5) << endl;
  cout << st.mrq(1, 10) << endl;

  return 0;
}
