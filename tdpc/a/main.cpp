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

// int N;
// vector<int> p;
// set<int> ans;
// int rec(int i, int score) {
//   if (i == N) {
//     ans.insert(score);
//     return 0;
//   }

//   // 得点しないとき
//   rec(i + 1, score);
//   // 得点するとき
//   rec(i + 1, score + p[i]);

//   return 0;
// }

// // N問の問題i問目の配点はpi
// // 得点は何通り考えられるか
// // 再帰で解いてみる
// int main() {
//   cin >> N;
//   p.resize(N);
//   rep(i, N) cin >> p[i];
//   rec(0, 0);
//   cout << ans.size() << endl;
// }


int main() {
  int N; cin >> N;
  vector<int> p(N);
  rep(i, N) cin >> p[i];

  sort(all(p));

  // たかだか10000点だからboolで持つ？
  vector<vector<bool>> dp(N + 1, vector<bool>(10001, false));
  dp[0][0] = true;
  // dp[i][10000]みたいな感じ？
  // dp[N]で回してfalseが答え？
  rep(i, N) {
    rep(j, 10001) {
      // 解くとき
      if (j >= p[i]) {
        dp[i + 1][j] = dp[i + 1][j] || dp[i][j - p[i]];
      }
      // 解かないとき
      dp[i + 1][j] = dp[i + 1][j] || dp[i][j];
    }
  }
  int ans = 0;
  rep(i, 10001) {
    if (dp[N][i]) ans++;
  }
  cout << ans << endl;
}