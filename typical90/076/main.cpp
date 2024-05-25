#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;

  vector<ll> A(N + 1);
  vector<ll> B(N * 2 + 1);
  rep2(i, 1, N + 1) cin >> A.at(i);

  rep2(i, 1, N + 1) B.at(i) = B.at(i - 1) + A.at(i);
  rep2(i, 1, N + 1) B.at(i + N) = B.at(i + N - 1) + A.at(i);
  if (B.at(N) % 10ll != 0LL) {
    cout << "No" << endl;
    return 0;
  }

  rep(i, N) {
    ll goal = B.at(i) + B.at(N) / 10;
    auto pos = lower_bound(B.begin(), B.end(), goal);
    if (*pos == goal) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
