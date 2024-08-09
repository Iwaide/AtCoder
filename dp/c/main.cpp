#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
  int N; cin >> N;
  vector<vector<int>> activities;
  rep(i, N) {
    int a, b, c; cin >> a >> b >> c;
    activities.push_back(vector<int>{a, b, c});
  }

  vector<vector<int>> dp(N);
  rep(i, N) {
    dp[i] = vector<int>(3, 0);
  }
  dp[0][0] = activities[0][0];
  dp[0][1] = activities[0][1];
  dp[0][2] = activities[0][2];
  rep(i, N - 1) {
    rep(j, 3) {
      rep(k, 3) {
        if (j != k) {
          dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + activities[i + 1][j]);
        }
      }
    }
  }
  int ans = 0;
  rep(i, 3) {
    chmax(ans, dp[N - 1][i]);
  }
  cout << ans << endl;
}
