#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  int Mi, Ri;
  rep(i, S.size()) {
    if (S.at(i) == 'M') {
      Mi = i;
    } else if (S.at(i) == 'R') {
      Ri = i;
    }
  }
  if (Ri < Mi) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

