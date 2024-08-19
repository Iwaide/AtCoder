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

map<ll, ll> memo;
ll rec(ll hp) {
  if (hp <= 0) {
    return 0LL;
  }
  if (hp == 1) {
    return 1LL;
  }
  if (hp > 1) {
    return 1LL + 2 * rec(hp / 2);
  }
}

int main() {
  ll H; cin >> H;
  ll ans = rec(H);
  cout << ans << endl;
}

