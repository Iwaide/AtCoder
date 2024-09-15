#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()
template<typename T>
void print_vector(vector<T> &vec) {
  rep(i, vec.size()) {
    if (i != vec.size() - 1) {
      cout << vec[i] << " ";
    } else {
      cout << vec[i] << endl;
    }
  }
}

// グラフG, Hを同型にするときの最低金額を求める
// 同型である、とは頂点番号が違っても同じ形であればいいみたいな感じ
// 同型である、の判定が難しいな
// 各頂点に対する対応関係を全部出して、そこから辺をアレコレする？
// 1 -> 2, 2-> 3, 3 -> 4, 4->1みたいな感じ？
// 辺そのものはGとHをループしてやればいいか
int main() {
  int N, MG, MH;
  cin >> N >> MG;
  map<int, set<int>> G;
  map<int, set<int>> H;
  rep(i, MG) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  cin >> MH;
  rep(i, MH) {
    int a, b; cin >> a >> b;
    a--, b--;
    H[a].insert(b);
    H[b].insert(a);
  }
  vector<vector<int>> A(N, vector<int>(N));
  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      cin >> A[i][j];
      A[j][i] = A[i][j];
    }
  }
  // 対応関係用の配列作る。{ 0, 1, 2, 3, 4 }みたいなやつ
  // next_permutationで組み合わせを全網羅する
  vector<int> v(N);
  rep(i, N) v[i] = i;

  // 対応関係をグチャらせたことで、i < jの関係が崩れちゃってる気がする
  ll ans = LONG_LONG_MAX;
  do {
    ll tmp = 0;
    for(int i = 0; i < N - 1; i++) {
      for(int j = i + 1; j < N; j++) {
        // i, jはHの頂点に対する操作なんだけど、Gとの比較で見るときはviを経由する
        // G側に辺があるとき
        if (G[v[i]].count(v[j])) {
          // H側に辺が無いとき追加しないといけない
          if (!H[i].count(j)) tmp += A[i][j];
        // G側に辺が無いとき
        } else {
          // H側に辺があるとき消さないといけない
          if (H[i].count(j)) tmp += A[i][j];
        }
      }
    }
    chmin(ans, tmp);
  } while(next_permutation(all(v)));

  cout << ans << endl;
}
