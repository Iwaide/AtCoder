#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int H, W, X, Y;
  cin >> H >> W >> X >> Y;
  X--;
  Y--;
  vector<vector<char>> S(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> S.at(i).at(j);
  int result = 1;
  for(int i = X - 1; i >= 0; i--) {
    if (S.at(i).at(Y) == '#') {
      break;
    } else {
      result++;
    }
  }
  // // 縦の下方向
  for(int i = X + 1; i < H; i++) {
    if (S.at(i).at(Y) == '#') {
      break;
    } else {
      result++;
    }
  }
  // // 横の左方向
  for(int i = Y - 1; i >= 0; i--) {
    if (S.at(X).at(i) == '#') {
      break;
    } else {
      result++;
    }
  }
  // // 横の右方向
  for(int i = Y + 1; i < W; i++) {
    if (S.at(X).at(i) == '#') {
      break;
    } else {
      result++;
    }
  }
  cout << result << endl;
}
