#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int A, B;
  cin >> A >> B;
  rep(i, 2000) {
    if (i * 8 / 100 == A && i / 10 == B) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}

