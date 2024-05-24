#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<vector<char>> board(10, vector<char>(10));

void fill_land(vector<vector<bool>> &checked, int y, int x) {
  if (y < 0 || y > 9 || x < 0 || x > 9) return;
  if (checked.at(y).at(x)) return;
  if (board.at(y).at(x) == 'x') return;

  checked.at(y).at(x) = true;

  fill_land(checked, y - 1, x);
  fill_land(checked, y, x - 1);
  fill_land(checked, y, x + 1);
  fill_land(checked, y + 1, x);
}

bool check_connected() {
  int y = -1, x = -1;
  rep(i, 10) {
    rep(j, 10) {
      if (board.at(i).at(j) == 'o') {
        y = i;
        x = j;
        break;
      }
    }
    if (y > 0 && x > 0) {
      break;
    }
  }
  vector<vector<bool>> checked(10, vector<bool>(10, false));
  fill_land(checked, y, x);

  bool connected = true;
  rep(i, 10) {
    rep(j, 10) {
      if (board.at(i).at(j) == 'o' && !checked.at(i).at(j)) {
        connected = false;
        break;
      }
    }
    if (!connected) break;
  }
  return connected;
}

int main() {
  rep(i, 10) rep(j, 10) cin >> board.at(i).at(j);

  rep(i, 10) {
    rep(j, 10) {
      if (board.at(i).at(j) == 'x') {
        board.at(i).at(j) = 'o';
        if (check_connected()) {
          cout << "YES" << endl;
          return 0;
        }
        board.at(i).at(j) = 'x';
      }
    }
  }
  cout << "NO" << endl;
}
