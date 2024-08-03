#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// 1, 2, 3のとき
// 2, 3, 3
// 4, 3, 3
// 4, 4, 4
// 2, 4, 4のとき
// 4, 4, 4
// 2, 2, 3のとき
// 3, 3, 3
// 最終の数をXとすると (3X - (A + B + C)) / 2回
// 上記の式は割り切れないといけないので、
// A + B + Cが偶数のとき Xは偶数, A + B + C奇数のときXも奇数
// 一番大きい数字をXに合わせる必要がある
int main() {
  int A, B, C; cin >> A >> B >> C;
  int maximum = max(A, max(B, C));
  if ((A + B + C) % 2 != maximum % 2) {
    maximum++;
  }
  cout << (3 * maximum - (A + B + C)) / 2 << endl;
}

