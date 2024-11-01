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

// シルクロードにはN+1個の都市がありi-1とiの都市間の距離はDi
// M日以内に0からNまで絹を運ぶことになった
// 移動: 現在の都市から一つ東(i - 1からi)の都市に１日かけて移動する
// 待機: 移動を行わず現在いる都市で１日待機する
// j日目の天候の悪さはCj
// 都市i-1から都市iに移動する場合Di*Cjの披露が溜まる
// できるだけ疲労度を貯めずに移動したい
// 1 <= N <= M <= 1000
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> D(N), C(M);
  rep(i, N) cin >> D[i];
  rep(i, M) cin >> C[i];

  // 日数と都市でDP?
  vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
  dp[0][0] = 0;
  rep(i, M) {
    // 各都市
    rep(j, N) {
      // INT_MAXのときは到達不可
      if (dp[i][j] == INT_MAX) continue;
      // 休む: 前日の同じ都市がスライド
      chmin(dp[i + 1][j], dp[i][j]);
      // 動く: 次の都市へ。距離 * 天候の悪さ
      chmin(dp[i + 1][j + 1], dp[i][j] + D[j] * C[i]);
    }
  }
  int ans = INT_MAX;
  rep(i, M + 1) {
    chmin(ans, dp[i][N]);
  }
  cout << ans << endl;
}
