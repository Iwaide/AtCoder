#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long A, B, K;
  cin >> A >> B >> K;
  rep2(i, A, B + 1) {
    if (i <= (A + K - 1) || i >= (B - K + 1)) {
      cout << i << endl;
    }
  }
}

