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

// N + 1個の街があり、i番目の街はAi体のモンスターに襲われている
// N人の勇者がいて、i番目の勇者はi or i + 1の街を襲っているモンスターを合計でBi体まで倒せる
// 最大で何体のモンスターを倒せるか
// i+1のところ倒したほうがいいときってiが0のときだけか？
// とりあえず全員でi倒して、余ったらi+1行くでいい気がするけど
int main() {
  int N; cin >> N;
  vector<int> A(N + 1), B(N);
  rep(i, N + 1) cin >> A[i];
  rep(i, N) cin >> B[i];

  ll ans = 0;
  rep(i, N) {
    int mons = min(A[i], B[i]);
    ans += mons;
    if (B[i] > mons) {
      int yojyou = min(B[i] - mons, A[i + 1]);
      ans += yojyou;
      A[i + 1] -= yojyou;
    }
  }
  cout << ans << endl;
}

