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

int N;
vector<ll> A;

vector<vector<ll>> memo;
// iはindex, dは倒した数の偶奇
ll solve(int i, int d) {
  if (i == N) {
    return 0;
  }
  if (memo[i][d] != -1) {
    return memo[i][d];
  }
  ll ans = 0;
  // 倒さないとき
  chmax(ans, solve(i + 1, d));
  // 倒すとき
  ll n = (d + 1) % 2 == 0 ? 2 : 1;
  chmax(ans, A[i] * n + solve(i + 1, (d + 1) % 2));

  return memo[i][d] = ans;
}

// N匹のモンスターを倒すi匹目のモンスターの強さはAi
// モンスターを逃したとき、得られる経験値は0
// 強さがXのモンスターを倒したとき経験値Xを得る、ただし、モンスターを倒すのが偶数回のときは代わりに2X得る
// 一回普通に再帰で書いてみるか
int main() {
  cin >> N;
  A.resize(N);
  memo = vector<vector<ll>>(N + 1, vector<ll>(2, -1));
  rep(i, N) cin >> A[i];

  ll ans = solve(0, 0);
  cout << ans << endl;
}
