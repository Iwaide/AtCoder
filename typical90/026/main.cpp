#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int N;
map<int, set<int>> G;
vector<int> col;

// curは0, 1の色
void dfs(int pos, int cur) {
  col[pos] = cur;
  for (int p : G[pos]) {
    if (col[p] == -1) {
      dfs(p, 1 - cur);
    }
  }
}

int main() {
  cin >> N;
  col.resize(N + 1, -1);

  rep(i, N - 1) {
    int A, B;
    cin >> A >> B;
    G[A].insert(B);
    G[B].insert(A);
  }
  dfs(1, 0);
  vector<int> G1, G2;
  rep2(i, 1, N + 1) {
    if (col[i] == 0) {
      G1.push_back(i);
    } else {
      G2.push_back(i);
    }
  }
  if (G1.size() > G2.size()) {
    for(int i = 0; i < (N / 2); i++) {
      if (i) cout << " ";
      cout << G1[i];
    }
  } else {
    for(int i = 0; i < (N / 2); i++) {
      if (i) cout << " ";
      cout << G2[i];
    }
  }
  cout << endl;
}
