#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  int AB2 = abs(xb - xa) * abs(xb - xa) + abs(yb - ya) * abs(yb - ya);
  int AC2 = abs(xc - xa) * abs(xc - xa) + abs(yc - ya) * abs(yc - ya);
  int BC2 = abs(xc - xb) * abs(xc - xb) + abs(yc - yb) * abs(yc - yb);
  if ((AB2 == (AC2 + BC2)) || (AC2 == (AB2 + BC2)) || (BC2 == (AB2 + AC2))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

