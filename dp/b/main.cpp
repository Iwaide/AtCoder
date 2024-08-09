#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K; cin >> N >> K;
  vector<int> h(N);
  rep(i, N) cin >> h[i];
  vector<int> dp(N, 1e9);
  dp[0] = 0;
  for(int i = 0; i < N - 1; i++) {
    for(int j = 1; j + i < N && j <= K; j++) {
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
    }
  }
  cout << dp[N - 1] << endl;
}
