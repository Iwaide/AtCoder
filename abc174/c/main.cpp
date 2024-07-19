#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// NOTE: 筆算をすればよくて、modに同じ数が出てくると循環してるはずだから
// K回ぐらい割り算すれば鳩の巣理論で割り切れるかどうか判断できる
int main() {
  int K;
  cin >> K;
  
  int cur = 0;
  rep2(i, 1, K + 1) {
    cur = cur * 10 + 7;
    cur %= K;
    if (cur == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}

