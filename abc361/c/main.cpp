#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  rep(i, N) cin >> A.at(i);
  sort(A.begin(), A.end());
  long long ans = LLONG_MAX;
  int kukan = N - K;
  for(int i = 0; i <= N - kukan; i++) {
    long long diff = A.at(i + kukan - 1) - A.at(i);
    ans = min(diff, ans);
  }
  cout << ans << endl;
}

