#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  rep(i, N) cin >> A.at(i);
  vector<long long> cs(N + 1, 0);
  rep(i, N) cs.at(i + 1) = cs.at(i) + A.at(i);
  for(int i = 1; i <= N; i++) {
    long long ans = 0;
    for(int j = 0; j <= N - i; j++) {
      ans = max(ans, cs.at(i + j) - cs.at(j));
    }
    cout << ans << endl;
  }
}

