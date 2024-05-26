#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  if (S.at(0) != 'A') {
    cout << "WA" << endl;
    return 0;
  }
  int index = -1;
  rep2(i, 2, S.size() - 1) {
    if (S.at(i) == 'C') {
      index = i;
      break;
    }
  }
  if (index < 0) {
    cout << "WA" << endl;
    return 0;
  }

  rep(i, S.size()) {
    if (i == 0 || i == index) continue;
    if (isupper(S.at(i))) {
      cout << "WA" << endl;
      return 0;
    }
  }
  cout << "AC" << endl;
}

