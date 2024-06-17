#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   string S;
//   cin >> S;
//   int N = S.size() + 1;
//   vector<int> a(N, 0);
//   rep(i, N - 1) {
//     if (S.at(i) == '<') {
//       a.at(i + 1) = a.at(i) + 1;
//     }
//   }
//   for(int i = N - 1 - 1; i >= 0; i--) {
//     if (S.at(i) == '>') {
//       a.at(i) = max(a.at(i), a.at(i + 1) + 1);
//     }
//   }
//   long long ans = 0;
//   rep(i, N) ans += 1LL * a.at(i);
//   cout << ans << endl;
// }

int main() {
  string S;
  cin >> S;
  int N = S.size() + 1;
  vector<long long> a(N);
  rep(i, S.size()) {
    if (S.at(i) == '<') {
      a.at(i + 1) = a.at(i) + 1;
    }
  }
  for(int i = S.size() - 1; i >= 0; i--) {
    if (S.at(i) == '>') {
      a.at(i) = max(a.at(i + 1) + 1, a.at(i));
    }
  }
  cout << accumulate(a.begin(), a.end(), (long long)(0)) << endl;
}
