#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<double> cs(N + 1, 0);
  rep2(i, 1, N + 1) {
    double pi;
    cin >> pi;
    double exp = ((1 + pi)) / 2.0;
    cs.at(i) = cs.at(i - 1) + exp;
  }
  double ans = 0;
  rep(i, N - K + 1) {
    double tmp = (cs.at(i + K) - cs.at(i));
    ans = max(ans, tmp);
  }
  cout << fixed << std::setprecision(12) << ans << endl;
}

