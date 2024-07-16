#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<pair<long long, long long>> LR(N);
  long long minimum = 0;
  long long diff = 0;
  rep(i, N) {
    long long Li, Ri;
    cin >> Li >> Ri;
    minimum += Li;
    diff += (Ri - Li);
    LR[i] = make_pair(Li, Ri);
  }
  long long target = -1 * minimum;
  if (minimum <= 0 && diff >= target) {
    cout << "Yes" << endl;
    rep(i, N) {
      auto pair = LR[i];
      long long d = pair.second - pair.first;
      long long ans = pair.first + min(target, d);
      cout << ans;
      if (i == N - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
      target -= min(target, d);
    }
  } else {
    cout << "No" << endl;
  }
}

