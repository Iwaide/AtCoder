#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, Y;
  cin >> N >> Y;
  bool detected = false;
  rep(x, N + 1) {
    int yz = N - x;
    rep(y, yz + 1) {
      int z = yz - y;
      int total = 10000 * x + 5000 * y + 1000 * z;
      if (total == Y) {
        cout << x << " " << y << " " << z << endl;
        detected = true;
        break;
      }
    }
    if (detected) break;
  }
  if (!detected) cout << "-1 -1 -1" << endl;
}
