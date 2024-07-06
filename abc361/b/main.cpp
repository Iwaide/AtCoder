#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a, b, c, d, e, f;
  int g, h, i, j, k, l;
  cin >> a >> b >> c >> d >> e >> f;
  cin >> g >> h >> i >> j >> k >> l;
  if (!(j <= a || d <= g)) {
    if (!(k <= b || e <= h )) {
      if (!(l <= c || f <= i)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
