#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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
