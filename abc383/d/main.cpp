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

vector<bool> isPrime;

vector<ll> sieve(int n) {
  isPrime.resize(n, true);
  isPrime[0] = false;
  isPrime[1] = false;

  vector<ll> res;
  for(ll i = 2; i < n; i++) {
    if (isPrime[i]) {
      res.push_back(i);
      for(ll j = i * 2; j < n; j += i) isPrime[j] = false;
    }
  }
  return res;
}

int main() {
  ll N; cin >> N;
  vector<ll> primes = sieve(1000005);
  ll ans = 0;
  for(ll p : primes) {
    if (p * p * p * p > N) break;
    if (p < 100) {
      if (p * p * p * p * p * p * p * p <= N) ans++;
    }
    for(ll q : primes) {
      if (q <= p) continue;
      if (p * p * q * q <= N) {
        ans++;
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
