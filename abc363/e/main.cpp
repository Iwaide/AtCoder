#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int H, W, Y;
  cin >> H >> W >> Y;
  vector<vector<int>> I(H, vector<int>(W));
  rep(y, H) {
    rep(x, W) {
      cin >> I[y][x];
    }
  }
  rep(y, H) {
    if (y == 0 || y == H - 1) continue;
    rep(x, W) {
      if (x == 0 || x == W - 1) continue;
      int up = I[y - 1][x];
      int left = I[y][x - 1];
      int down = I[y + 1][x];
      int right = I[y][x + 1];
      int minimum = min(up, min(down, min(left, right)));
      I[y][x] = max(minimum, I[y][x]);
    }
  }
  vector<int> I2;
  rep(y, H) rep(x, W) I2.push_back(I[y][x]);
  sort(I2.begin(), I2.end());
  int all = W * H;
  rep2(i, 1, Y + 1) {
    auto pos = upper_bound(I2.begin(), I2.end(), i);
    if (pos == I2.end()) {
      cout << 0 << endl;
      break;
    }
    int index = pos - I2.begin();
    cout << all - index << endl;
  }
}

