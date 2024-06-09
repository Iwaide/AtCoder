#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  int capital_count = 0;
  int non_capital_count = 0;
  rep(i, S.size()) {
    if (isupper(S.at(i))) {
      capital_count++;
    } else {
      non_capital_count++;
    }
  }
  rep(i, S.size()) {
    if (capital_count > non_capital_count) {
      if (islower(S.at(i))) {
        S.at(i) = (char) (S.at(i) + ('A' - 'a'));
      }
    } else {
      if (isupper(S.at(i))) {
        S.at(i) = (char) (S.at(i) - ('A' - 'a'));
      }
    }
  }
  cout << S << endl;
}

