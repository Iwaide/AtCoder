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

// 幅Wしかない
// K枚より多くのスクリーンショットは貼り付けられない
// 重要度を最大化したい
// 1 <= W <= 10000
// 1 <= スクリーンショットの数N <= 50
// K枚
int main() {
  int W, N, K;
  cin >> W >> N >> K;
  // Aが幅、Bが重要度
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  // dp[i枚目][W][K] = 重要度
  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(10001, vector<int>(K + 1, 0)));
  
  // i枚目を貼るか、貼らないか
  rep(i, N) {
    // Wの幅
    rep(j, W + 1) {
      // i枚目を貼る
      if (A[i] <= j) {
      // 0からK-1までのやつに足していく
        rep(k, K) {
          chmax(dp[i + 1][j][k + 1], dp[i][j - A[i]][k] + B[i]);
        }
      }
      // 貼らない
      // 0からK枚のやつをスライドさせる
      rep(k, K + 1) {
        chmax(dp[i + 1][j][k], dp[i][j][k]);
      }
    }
  }
  int ans = 0;
  rep(i, W + 1) {
    rep(j, K + 1) {
      chmax(ans, dp[N][i][j]);
    }
  }
  cout << ans << endl;
}

