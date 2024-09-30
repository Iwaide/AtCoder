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

const ll MOD = 1000000007LL;

// MODの逆元を計算
ll mod_inverse(ll a, ll mod) {
  ll m0 = mod, t, q;
  ll x0 = 0, x1 = 1;
  if (mod == 1) return 0;
  while (a > 1) {
    q = a / mod;
    t = mod;
    mod = a % mod, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0) x1 += m0;
  return x1;
}


ll mod_combination(ll a, ll b, ll mod) {
  if (b == 0) return 1;

  ll ans = 1;
  for (int i = 0; i < b; i++) {
    ans = ans * (a - i) % mod;
    ans = ans * mod_inverse(i + 1, mod) % mod;
  }
  return ans;
}


// Nを1とLで埋めるときの場合の数
int N, L;

int main() {
  cin >> N >> L;
  int div = N / L;
  ll ans = 0;
  // iはLの個数
  for (int i = 0; i <= div; i++) {
    int rest = N - L * i;
    int c = rest + i;
    ans = (ans + mod_combination(c, i, MOD)) % MOD;
  }
  cout << ans << endl;
}
