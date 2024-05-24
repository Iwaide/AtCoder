#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;

  // 1.の出力
  x++;
  cout << x << endl;

  x *= (a + b);
  cout << x << endl;

  // ここにプログラムを追記
  x *= x;
  cout << x << endl;

  x -= 1;
  cout << x << endl;
}
