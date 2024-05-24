#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N;
  int K;
  cin >> N >> K;
  rep(i, K) {
    if (N % 200 == 0) {
      N = N / 200;
    } else {
      N = N * 1000 + 200;
    }
  }
  cout << N << endl;
}

