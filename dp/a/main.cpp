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
long long INF = 1LL << 60;

// // 幅優先で解いてみた。TLEする
// int rec(int i) {
//   if (i == 0) {
//     return 0;
//   }
//   long long result = INF;
//   // i - 1からきたとき
//   if (i - 1 >= 0) {
//     result = min(result, rec(i - 1) + abs(h[i] - h[i - 1]));
//   }
//   if (i - 2 >= 0) {
//     result = min(result, rec(i - 2) + abs(h[i] - h[i - 2]));
//   }

//   return result;
// }

// int main() {
//   cin >> N;
//   h.resize(N, 0);
//   rep(i, N) cin >> h[i];

//   long long ans = rec(N - 1);

//   cout << ans << endl;
// }

// メモ化する
// vector<long long> memo;
// int rec(int i) {
//   if (memo[i] != -1) {
//     return memo[i];
//   }

//   if (i == 0) {
//     return 0;
//   }

//   long long result = INF;
//   // i - 1からきたとき
//   if (i - 1 >= 0) {
//     result = min(result, rec(i - 1) + abs(h[i] - h[i - 1]));
//   }
//   if (i - 2 >= 0) {
//     result = min(result, rec(i - 2) + abs(h[i] - h[i - 2]));
//   }

//   return memo[i] = result;
// }

// int main() {
//   cin >> N;
//   h.resize(N, 0);
//   memo.resize(N, -1);
//   rep(i, N) cin >> h[i];

//   long long ans = rec(N - 1);

//   cout << ans << endl;
// }

// DPで解く
int main() {
  cin >> N;
  h.resize(N);
  rep(i, N) cin >> h[i];
  vector<long long> dp(N, LONG_LONG_MAX);
  dp[0] = 0;
  for(int i = 1; i < N; i++) {
    dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));

    if (1 < i) {
      dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
  }
  cout << dp[N - 1] << endl;
}
