#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<long long> cs(N + 1, 0);
  rep(i, N) {
    long long Ai;
    cin >> Ai;
    cs[i + 1] = cs[i] + Ai;
  }
  map<long long, set<int>> m;
  rep(i, N + 1) m[cs[i]].insert(i);
  long long ans = 0;
  for(auto pair : m) {
    long long cnt = pair.second.size();
    ans += (cnt * (cnt - 1LL)) / 2LL;
  }
  cout << ans << endl;
}

