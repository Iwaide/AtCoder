#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K, x = 1;
  cin >> N >> K;
  rep(i, N) {
    if (x * 2 > x + K) {
      x += K;
    } else {
      x *= 2;
    }
  }
  cout << x << endl;
}
