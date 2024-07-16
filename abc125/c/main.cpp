#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

long long dcg(long long a, long long b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  rep(i, N) cin >> A[i];
  vector<long long> L(N + 1, 0);
  rep(i, N) L[i + 1] = gcd(L[i], A[i]);

  vector<long long> R(N + 1, 0);
  for(int i = N - 1; i >= 0; i--) R[i] = gcd(R[i + 1], A[i]);

  long long res = 0;
  rep(i, N) {
    long long l = L[i];
    long long r = R[i + 1];
    res = max(res, gcd(l, r));
  }
  cout << res << endl;
}
