#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long Sx, Sy, Tx, Ty;
  cin >> Sx >> Sy >> Tx >> Ty;
  bool is_start_left = (Sx + Sy) % 2 == 0;
  long long deltaX = Tx - Sx;
  bool is_move_to_left = deltaX < 0;
  long long deltaY = Ty - Sy;
  long long yohaku = 0;
  if (deltaX != 0 && (!is_start_left && is_move_to_left) || (is_start_left && !is_move_to_left)) {
    yohaku = 1;
  }
  long long ans = abs(deltaY);
  long long costX = (max(0LL, (abs(deltaX) - (yohaku + abs(deltaY)))) + 1) / 2;
  ans += costX;
  cout << ans << endl;
}

