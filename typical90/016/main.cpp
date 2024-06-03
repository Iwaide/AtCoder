#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long A, B, C, N;
  cin >> N >> A >> B >> C;
  long long result = 9999;
  rep(a, 10000) {
    rep(b, 10000) {
      long long rest = N - A * a - B * b;
      if (rest < 0) continue;
      if (rest % C == 0) {
        result = min(result, a + b + (rest / C));
      }
    }
  }
  cout << result << endl;
}

