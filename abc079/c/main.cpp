#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

char to_operator(bool b) {
  return b ? '+' : '-';
}

int main() {
  string S;
  cin >> S;

  bitset<3> result;
  rep(i, (1 << 3)) {
    bitset<3> s(i);
    int tmp = S.at(0) - '0';
    rep(j, 3) {
      if (s.test(j)) {
        tmp += (S.at(j + 1) - '0');
      } else {
        tmp -= (S.at(j + 1) - '0');
      }
    }
    if (tmp == 7) {
      result = s;
      break;
    }
  }
  cout << S.at(0) << to_operator(result.test(0)) <<
    S.at(1) << to_operator(result.test(1)) <<
    S.at(2) << to_operator(result.test(2)) <<
    S.at(3) << "=7" << endl;
}

