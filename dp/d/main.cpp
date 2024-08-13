#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()

int main() {
  int N, W;
  cin >> N >> W;
  vector<pair<int, ll>> goods;
  rep(i, N) {
    int w; ll v;
    cin >> w >> v;
    goods.push_back(make_pair(w, v));
  }
  sort(all(goods));
  vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0LL));
  rep(i, N) {
    auto item = goods[i];
    rep2(j, 1, W + 1) {
      if (j >= item.first) {
        chmax(dp[i+1][j], max(dp[i][j], item.second + dp[i][j - item.first])); 
      } else {
        dp[i+1][j] = dp[i][j];
      }
    }
  }
  cout << dp[N][W] << endl;
}

