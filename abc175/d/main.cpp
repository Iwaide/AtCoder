#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main() {
  int N; long long K;
  cin >> N >> K;
  vector<int> P(N);
  vector<long long> C(N);
  rep(i, N) {
    cin >> P[i];
    P[i]--;
  }
  rep(i, N) cin >> C[i];
  long long res = -INF;

  // まずループを作る
  vector<bool> vis(N, false);
  vector<vector<long long>> ss;
  rep(i, N) {
    if (vis[i]) continue;

    vector<long long> s;
    int current = i;
    while(!vis[current]) {
      vis[current] = true;
      s.push_back(C[current]);
      current = P[current];
    }
    ss.push_back(s);
  }

  // 各サイクルごとに考える
  for(auto vec: ss) {
    long long M = vec.size();
    // サイクルを2周したものの累積和を取っておく
    // 連続するr個の総和の最大値をとるときにループするケースもそのまま計算できるため
    vector<long long> sum(M * 2 + 1, 0);
    rep(i, M * 2) sum[i + 1] = sum[i] + vec[i % M];

    // amari[r] 連続するr個の総和の最大値, rとはM以下の数
    vector<long long> amari(M, -INF);
    rep(i, M) {
      rep(j, M) {
        chmax(amari[j], sum[i+j] - sum[i]);
      }
    }

    // rは連続する個数
    for(int r = 0; r < M; ++r) {
      if (r > K) continue;

      // ループ回数
      long long q = (K - r) / M;
      // 連続する個数が0, ループ0のときはケース外
      if (r == 0 && q == 0) continue;

      // 正のループのときと負のループのときとで場合分け
      if (sum[M] > 0) chmax(res, amari[r] + sum[M] * q);
      else if (r > 0) chmax(res, amari[r]);
    }
  }
  cout << res << endl;
}

