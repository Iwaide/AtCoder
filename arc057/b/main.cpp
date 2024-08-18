#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()
const int INF = 1e9+7;

// i日目までにj回勝率が上昇したときの勝利数の最小値
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  vector<int> sum(N+1);
  rep(i, N) {
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
  }
  // 全勝してると機嫌が良い日が1日より多くなることはない
  if (sum[N] == K) {
    cout << 1 << endl;
    return 0;
  }

  vector<vector<int>> dp(N+1, vector<int>(N+1, INF));
  dp[0][0] = 0;
  // N日目に
  rep(i, N) {
    // J回機嫌が良くなるようにする
    for(int j = 0; j <= i; j++) {
      if (dp[i][j] < INF) {
        // 勝たない
        chmin(dp[i+1][j], dp[i][j]);
        // 勝つ
        if (i == 0) {
          // 初日は1回だけ勝つのが最小
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);
        } else {
          // 勝率を上げるために最小限必要な勝利数は下記の等式でwinに1足したもの
          // win / sum[i+1] = dp[i][j] / sum[i]
          // win = dp[i][j] * sum[i+1] / sum[i] + 1;
          ll atleast = (ll)dp[i][j] * sum[i+1] / sum[i] + 1;
          if (atleast <= (a[i] + dp[i][j])) {
            dp[i+1][j+1] = min(dp[i+1][j+1], (int) atleast);
          }
        }
      }
    }
  }
  for(int i = N; i >= 0; i--) {
    if (dp[N][i] <= K) {
      cout << i << endl;
      return 0;
    }
  }
}

