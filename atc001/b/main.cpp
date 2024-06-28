#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

struct UnionFind {
  vector<int> p;
  vector<int> r;
  UnionFind(int n) {
    p.resize(n, -1);
    r.resize(n, 1);
  }

  int find(int x) {
    if (p[x] == -1) return x;
    return p[x] = find(p[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (r[x] > r[y]) {
      swap(x, y);
    }
    if (r[x] == r[y]) {
      r[y]++;
    }
    p[x] = y;
  }
};

int main() {
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(N); 
  rep(i, Q) {
    int P, A, B;
    cin >> P >> A >> B;
    if (P == 0) {
      uf.unite(A, B);
    } else {
      if (uf.find(A) == uf.find(B)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}

