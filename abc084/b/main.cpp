#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  bool valid = true;
  rep(i, S.size()) {
    if (i == A) {
      valid = valid && S.at(i) == '-';
    } else {
      valid = valid && isdigit(S.at(i));
    }
  }
  cout << (valid ? "Yes" : "No") << endl;
}

