#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int S, T;
  cin >> S >> T;
  long long result = 0;
  rep(i, 101) {
    rep(j, 101) {
      rep(k, 101) {
        if ((i + j + k) <= S && (i * j * k) <= T) {
          result++;
        }
      }
    }
  }
  cout << result << endl;
}

