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

ll N, X;
vector<ll> patty;
vector<ll> burger;

ll rec(ll l, ll x) {
  if (l == 0) {
    return (x <= 0 ? 0 : 1);
  }
  if (x == 0 || x == 1) {
    return 0;
  }

  if (1 < x && x <= (1 + burger[l-1])) {
    return rec(l-1, x - 1);
  } else if (x == (2 + burger[l-1])) {
    return 1 + patty[l-1];
  } else if (2 + burger[l-1] < x && x <= (2 * burger[l-1]) + 2) {
    return 1 + patty[l-1] + rec(l-1, x - burger[l-1] - 2);
  } else if (x == 3 + 2 * burger[l-1]) {
    return 1 + 2 * patty[l-1];
  }
}

int main() {
  cin >> N >> X;

  patty.resize(N+1);
  burger.resize(N+1);
  patty[0] = 1;
  burger[0] = 1;
  rep(i, N) {
    patty[i+1] = patty[i] * 2 + 1;
    burger[i+1] = burger[i] * 2 + 3;
  }
  ll ans = rec(N, X);
  cout << ans << endl;
}

