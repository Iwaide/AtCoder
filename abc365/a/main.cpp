#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int Y; cin >> Y;
  if (Y % 4 != 0) {
    cout << 365 << endl;
  } else {
    if (Y % 100 != 0) {
      cout << 366 << endl;
    } else if (Y % 400 != 0) {
      cout << 365 << endl;
    } else if (Y % 400 == 0) {
      cout << 366 << endl;
    }
  }
}

