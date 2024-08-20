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

ll calc_or(vector<ll> &v) {
  ll res = 0;
  for(ll l : v) {
    res |= l;
  }
  return res;
}

int N;
vector<ll> A;
// 1 (/) 2 (/) 3
int main() {
  cin >> N; A.resize(N);
  rep(i, N) cin >> A[i];

  ll ans = LONG_LONG_MAX;
  rep2(i, 1, 1 << (N - 1)) {
    bitset<20> b(i);
    ll xored = 0;
    ll ored = 0;
    for (int j = 0; j <= N; j++) {
      if (j < N) ored |= A[j];
      if (j == N || b.test(j)) {
        xored ^= ored;
        ored = 0;
      }
    }
    chmin(ans, xored);
  }
  cout << ans << endl;
}

