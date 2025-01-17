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
  int N, M;
  int A[101], B[101];
  cin >> N >> M;
  // 辺の情報
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  int ans = 0;
  rep(i, M) {
    UnionFind uf(N);
    // i以外の辺で頂点をつなげる
    rep(j, M) if (j != i) uf.unite(A[j], B[j]);
    int c = 0;
    rep(j, N) if(j == uf.find(j)) c++;
    if (1 < c) ans++;
  }
  cout << ans << endl;
}

