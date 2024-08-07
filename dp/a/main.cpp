#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// N個の足場に高さhiが振られている
// 足場1からカエルスタート。i+1 か i+2に飛ぶ
// 飛んだ足場の高さの差がコストになる
// 足場Nにたどり着くまでのコストの総和の最小値
int N;
vector<long long> h;

// メモ化再帰で解く
// vector<long long> dp;
// long long rec(int index) {
//   if (dp[index] != -1) {
//     return dp[index];
//   }
//   if (index == 0) {
//     return 0;
//   }

//   long long ans1 = LONG_LONG_MAX;
//   if (index - 1 >= 0) {
//     ans1 = rec(index - 1) + abs(h[index] - h[index - 1]);
//   }

//   long long ans2 = LONG_LONG_MAX;
//   if (index - 2 >= 0) {
//     ans2 = rec(index - 2) + abs(h[index] - h[index - 2]);
//   }
//   return dp[index] = min(ans1, ans2);
// }

// int main() {
//   cin >> N;
//   h.resize(N);
//   dp.resize(N, -1);
//   rep(i, N) cin >> h[i];
//   long long ans = rec(N - 1);
//   cout << ans << endl;
// }

// DPで解く
vector<long long> dp;
int main() {
  cin >> N;
  h.resize(N);
  rep(i, N) cin >> h[i];

  dp.resize(N, LONG_LONG_MAX);
  dp[0] = 0;

  for(int i = 1; i < N; i++) {
    if (i - 1 >= 0) {
      dp[i] = dp[i - 1] + abs(h[i] -h[i - 1]);
    }
    if (i - 2 >= 0) {
      dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
  }
  cout << dp[N - 1] << endl;
}
