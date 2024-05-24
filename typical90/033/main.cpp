#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  if (H < 2) {
    cout << W << endl;
    return 0;
  } else if (W < 2) {
    cout << H << endl;
    return 0;
  } else {
    cout << ((H + 2 - 1) / 2) * ((W + 2 - 1) / 2) << endl;
    return 0;
  }

  vector<vector<char>> grid(H, vector<char>(W, 'o'));
  int result = 0;
  rep(y, H) {
    rep(x, W) {
      if (grid.at(y).at(x) == 'o') {
        grid.at(y).at(x) = '#';
        result++;
        if (y + 1 < H) {
          grid.at(y + 1).at(x) = '.';
          if (x + 1 < W) {
            grid.at(y + 1).at(x + 1) = '.';
          }
        }
        if (x + 1 < W) {
          grid.at(y).at(x + 1) = '.';
        }
      }
    }
  }
  cout << result << endl;
  // cout << ((H + 2 - 1) / 2) * ((W + 2 - 1) / 2) << endl;
}
