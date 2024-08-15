#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()

const int MAX_V = 100100;
const long long INF = 1LL<<60;
int main() {
  int N; ll W;
  cin >> N >> W;
  vector<pair<ll, int>> goods;
  rep(i, N) {
    ll w; int v;
    cin >> w >> v;
    goods.push_back(make_pair(w, v));
  }
  // dp[ i ][ sum_v ] := i-1 番目までの品物から価値が sum_v以下となるように選んだときの、重さの総和の最小値
  vector<vector<ll>> dp(N+1, vector<ll>(MAX_V, INF));
  dp[0][0] = 0;
  rep(i, N) {
    auto item = goods[i];
    for(int sum_v = 0; sum_v < MAX_V; ++sum_v) {
      // 選ぶとき
      if (sum_v - item.second >= 0) {
        chmin(dp[i+1][sum_v], dp[i][sum_v - item.second] + item.first);
      }
      // 選ばないとき
      chmin(dp[i+1][sum_v], dp[i][sum_v]);
    }
  }
  ll res = 0;
  for(int sum_v = 0; sum_v < MAX_V; sum_v++) {
    if (dp[N][sum_v] <= W) res = sum_v;
  }
  cout << res << endl;
}

