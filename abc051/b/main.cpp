#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int K, S;
  cin >> K >> S;
  int result = 0;
  rep(x, K + 1) {
    rep(y, K + 1) {
      int z = S - (x + y);
      if (z <= K && z >= 0) {
        result++;
      }
    }
  }
  cout << result << endl;
}

