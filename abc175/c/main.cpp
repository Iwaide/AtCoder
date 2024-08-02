#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// 数直線、座標X
// 正負にD移動をK回
// 座標の絶対値を最小にしたい
int main() {
  long long X, K, D;
  cin >> X >> K >> D;
  // 絶対値を求めたいのでXの正負を入れ替えていい
  if (X < 0) X = -X;
  // 0に近づこうとするが足りないとき
  long long div = X / D;
  if (div > K) {
    cout << X - D * K << endl;
    return 0;
  }
  // 0の前後を反復横飛びするはず
  if (div % 2 == K % 2) {
    cout << X - div * D << endl;
  } else {
    cout << (div + 1) * D - X << endl;
  }
}

