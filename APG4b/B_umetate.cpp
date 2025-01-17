#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<vector<char>> board(10, vector<char>(10));

void fill_island(vector<vector<bool>> &checked, int y, int x) {
  if (y < 0 || y > 9 || x < 0 || x > 9) return;
  if (board.at(y).at(x) == 'x') return;
  if (checked.at(y).at(x)) return;

  checked.at(y).at(x) = true;

  fill_island(checked, y - 1, x);
  fill_island(checked, y, x - 1);
  fill_island(checked, y, x + 1);
  fill_island(checked, y + 1, x);
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
    if (y >= 0 && x >= 0) {
      break;
    }
  }

  vector<vector<bool>> checked(10, vector<bool>(10, false));
  fill_island(checked, y, x);
  bool connected = true;
  rep(i, 10) {
    rep(j, 10) {
      if (board.at(i).at(j) == 'o') {
        if (!checked.at(i).at(j)) {
          connected = false;
        }
      }
    }
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

#include <bits/stdc++.h>
using namespace std;

// (y, x)から到達できるすべての陸地マスのcheckedをtrueにする
void fill_island(vector<vector<char>> &board, vector<vector<bool>> &checked, int y, int x) {
  if (y < 0 || x < 0 || y >= 10 || x >= 10) return;
  if (board.at(y).at(x) == 'x') return;
  if (checked.at(y).at(x)) return;

  checked.at(y).at(x) = true;  // 既に調べているという状態に変えておく
  fill_island(board, checked, y - 1, x    );  // 上
  fill_island(board, checked, y    , x + 1);  // 右
  fill_island(board, checked, y + 1, x    );  // 下
  fill_island(board, checked, y    , x - 1);  // 左
}

bool check_connected(vector<vector<char>> &board) {
  vector<vector<bool>> checked(10, vector<bool>(10, false));

  // 陸地マスを1つ探す
  int y, x;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (board.at(i).at(j) == 'o') {
        y = i;
        x = j;
        break;
      }
    }
  }
  /* 引数： 盤面, チェック二次元配列, y座標, x座標*/
  fill_island(board, checked, y, x);  // (y, x)から到達できるすべての陸地マスのcheckedをtrueにする

  bool ok = true;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (board.at(i).at(j) == 'o') {
        if (!checked.at(i).at(j)) {
          // 到達できていない陸地マスがある
          ok = false;
        }
      }
    }
  }

  // ok == true なら全ての陸地マスは繋がっている
  return ok;
}

int main() {
  vector<vector<char>> board(10, vector<char>(10));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> board.at(i).at(j);
    }
  }

  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      if (board.at(y).at(x) == 'o') continue;
      // (y, x)は海のマス
      // ここを埋め立てたと仮定して、島が1つになるかを判定

      board.at(y).at(x) = 'o';  // 埋め立てたと仮定する

      if (check_connected(board)) {
        cout << "YES" << endl;
        return 0;
      }

      board.at(y).at(x) = 'x';  // 戻す
    }
  }

  cout << "NO" << endl;
}
