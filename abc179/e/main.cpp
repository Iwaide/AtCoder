#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N, X, M;
  cin >> N >> X >> M;
  vector<long long> path;
  vector<long long> vis(M, -1);
  long long current = X;
  vis[current] = 0;
  path.push_back(current);
  rep2(i, 1, M + 1) {
    current = current * current % M;
    if (vis[current] >= 0) break;

    path.push_back(current);
    vis[current] = i;
  }



  long long ans = 0;
  if (N < path.size()) {
    rep(i, N) ans += path[i];
  } else {
    rep(i, vis[current]) {
      ans += path[i];
    }
    vector<long long> loop(path.begin() + vis[current], path.end());
    long long loop_cnt = (N - vis[current]) / loop.size();
    vector<long long> sum(loop.size() + 1);
    rep(i, loop.size()) sum[i + 1] = sum[i] + loop[i];
    ans += sum[loop.size()] * loop_cnt + sum[(N - vis[current]) % loop.size()];
  }

  cout << ans << endl;
}

