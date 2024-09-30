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

const ll MOD = 1000000007LL;

int main() {
  int N, L;
  cin >> N >> L;
  vector<ll> dp(N + 1);
  dp[0] = 1;
  rep2(i, 1, N + 1) {
    if (i - L < 0) {
      dp[i] = dp[i - 1];
    // L段登るとき
    } else {
      dp[i] = (dp[i - 1] + dp[i - L]) % MOD;
    }
  }
  cout << dp[N] << endl;
}
