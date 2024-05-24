#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int A, B;
  cin >> A >> B;
  if (A >= 13) {
    cout << B << endl;
  } else if (A >= 6 && A <= 12) {
    cout << B / 2 << endl;
  } else {
    cout << 0 << endl;
  }
}

