#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S; cin >> S;
  int N = S.size() + 1;
  vector<int> l(N, 0), r(N, 0);
  rep(i, S.size()) {
    if (S[i] == '<') {
      l[i + 1] = l[i] + 1;
    }
  }
  for(int i = S.size() - 1; i >= 0; i--) {
    if(S[i] == '>') {
      r[i] = r[i + 1] + 1;
    }
  }
  long long ans = 0;
  rep(i, l.size()) {
    ans += max(l[i], r[i]);
  }
  cout << ans << endl;
}
