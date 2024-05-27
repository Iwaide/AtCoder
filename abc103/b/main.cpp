#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S, T;
  cin >> S >> T;
  rep(i, S.size()) {
    if (S == T) {
      cout << "Yes" << endl;
      return 0;
    }
    S = S.substr(S.size() - 1, 1) + S.substr(0, S.size() - 1);
  }
  cout << "No" << endl;
}

