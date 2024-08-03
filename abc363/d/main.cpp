#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

long long TEN (int x) { return x == 0 ? 1 : TEN(x - 1) * 10; }

int main() {
  long long N;
  cin >> N;
  // 0が含まれるため
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  N--;
  // 1桁 => 9 * 10^0
  // 2桁 => 9 * 10^0
  // 3桁 => 9 * 10^1
  // 4桁 => 9 * 10^1
  rep2(d, 1, 37) {
    // d桁の総数
    long long cnt = 9LL * TEN((d + 1) / 2 - 1);
    if (cnt >= N) {
      // 2桁からは11始まりのため
      N--;
      // 半分の桁数で元となる文を作る
      N += TEN((d + 1) / 2  - 1);
      // 回分数を作る
      string S = to_string(N);
      string ans = S;
      // 奇数の桁数のとき
      if (d % 2 == 1) {
        S.resize(S.size() - 1);
        reverse(S.begin(), S.end());
      } else {
        reverse(S.begin(), S.end());
      }
      cout << ans + S << endl;
      return 0;
    } else {
      N -= cnt;
    }
  }
}