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

// 気合でメモ化再帰で解く
// int S;
// stack<int> st;
// vector<ll> memo;
// const ll CON = 1000000007;
// ll solve(ll i) {
//   if (memo[i] != -1) {
//     return memo[i];
//   }

//   if (i == S) {
//     return 1;
//   }
//   if (S - i < 3) {
//     return 0;
//   }
//   ll ans = 0;
//   for(int j = 3; j <= S - i; j++) {
//     st.push(j);
//     ans += solve(i + j) % CON;
//     st.pop();
//   }
//   return memo[i] = ans;
// }
// int main() {
//   cin >> S;
//   memo.resize(S + 1, -1);
//   cout << solve(0) % CON << endl;
// }
const int MOD = 1000000007;
int main() {
  int S;
  cin >> S;
  // 総和がvとなるような数列の個数
  vector<ll> dp(S + 1);
  dp[0] = 1;
  // dp[v]について考えるとき
  // 最後の項が3のとき、残りの総和をv-3にすればよいのでdp[v-3]通り
  // ....3になってるとき....の部分がdp[v-3]ってことか
  // ....4のときはdp[v-4]
  // ....Sのときはdp[S-S = 0]
  // dpをSまで計算する
  for(int v = 3; v <= S; v++) {
    // 各vについてdp[0]...dp[v-3]まで足してく
    // dp[v] = dp[v-3] + dp[v-4]...dp[0]
    // dp[v-1]  dp[v-4] ... dp[0]
    // 式変形で下記のように書ける
    // dp[v] = dp[v-3] + dp[v-1]
    dp[v] = (dp[v - 3] + dp[v - 1]) % MOD;
  }
  cout << dp[S] % MOD << endl;
}
