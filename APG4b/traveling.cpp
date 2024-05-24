#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int x = 0, y = 0, t = 0, N;
  cin >> N;
  bool succeeded = true;
  rep(i, N) {
    int T, X, Y;
    cin >> T >> X >> Y;
    int diff = abs(X - x) + abs(Y - y);
    int time = T - t;
    if ((time >= diff) && (time - diff) % 2 == 0) {
      x = X;
      y = Y;
      t = T;
    } else {
      succeeded = false;
      break;
    }
  }
  if (succeeded) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
