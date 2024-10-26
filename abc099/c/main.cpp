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

// 1円か6^x円か9^x円しか引き出せない
// N円引き出すのに最低何回操作が必要か
// int main() {
//   int N;
//   cin >> N;
//   vector<int> dp(N + 1, INT_MAX);
//   dp[0] = 0;
//   for(int i = 1; i <= N; i++) {
//     // 1円払うとき
//     chmin(dp[i], dp[i - 1] + 1);
//     // 6^x円払うとき
//     for(int j = 6; j <= i; j = j * 6) {
//       chmin(dp[i], dp[i - j] + 1);
//     }
//     // 9^x円払うとき
//     for(int j = 9; j <= i; j = j * 9) {
//       chmin(dp[i], dp[i - j] + 1);
//     }
//   }
//   cout << dp[N] << endl;
// }
int N;
vector<int> memo(100001, -1);
int f(int cu) {
  if (cu == 0) return 0;
  if (memo[cu] != -1) return memo[cu];

  int res = INT_MAX;

  // 1円支払い
  chmin(res, f(cu - 1) + 1);

  // 6^x円支払い
  int x = 6;
  while(x <= cu) {
    chmin(res, f(cu - x) + 1);
    x *= 6;
  }

  // 9^x円支払い
  x = 9;
  while(x <= cu) {
    chmin(res, f(cu - x) + 1);
    x *= 9;
  }

  return memo[cu] = res;
}

int main() {
  cin >> N;
  cout << f(N) << endl;
}