#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

long long TEN (int x) { return x == 0 ? 1 : TEN(x - 1) * 10; }

int main() {
  long long N;
  cin >> N;
  // 0が含まれているので0だけ除外
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  N--;

  // 桁ごとにループ
  for (int d = 1;; d++) {
    // d桁の回文数の数は9 * 10^x-1で表せる
    // xは桁数を2で割った数の切り上げで求められる
    int x = (d + 1) / 2;
    // d桁の回文数よりNが小さいとき
    if (N <= 9 * TEN(x - 1)) {
      // 回文数は 1001, 1111, 1221, 1331...のように上位x桁は自然数が並んでいる
      // 回文数の上位x桁を取り出してできる整数の値、最初の1桁は1から始まらないといけないので、10^x-1からスタートして
      // 10~からスタートなので1個ぶんずらす
      string S = to_string(TEN(x - 1) + N - 1);
      // Sを空白でd桁にresize
      S.resize(d, ' ');
      // 回文になるようにSに値を詰めていく
      for(int i = x; i < d; i++) S[i] = S[d - 1 - i];
      cout << S << endl;
      return 0;
    } else {
      N -= 9 * TEN(x - 1);
    }
  }
}

