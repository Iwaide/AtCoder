#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int X;
  cin >> X;
  int result = 0;
  rep2(b, 1, 40) {
    int tmp = b;
    rep(p, 40) {
      tmp = tmp * b;
      if (tmp <= X) {
        result = max(result, tmp);
      } else {
        break;
      }
    }
  }
  cout << result << endl;
}

