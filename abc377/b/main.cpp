#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()
template<typename T>
void print_vector(vector<T> &vec) {
  rep(i, vec.size()) {
    if (i != vec.size() - 1) {
      cout << vec[i] << " ";
    } else {
      cout << vec[i] << endl;
    }
  }
}

// 8 * 8のマス目
// 空かコマがおかれている .#で表される
// すでに置かれているどのコマにも取られないようにいずれかの空マスにコマを置きたい
// コマを置けるマスがいくつあるか求めよ
int main() {
  vector<vector<bool>> board(8, vector<bool>(8, true));
  rep(i, 8) {
    rep(j, 8) {
      char c; cin >> c;
      // 空マスなら何もしない
      if (c == '.') continue;
      
      // コマが置かれているとき
      // 縦埋め
      rep(k, 8) {
        board[k][j] = false;
        board[i][k] = false;
      }
    }
  }
  int ans = 0;
  rep(i, 8) {
    rep(j, 8) {
      if (board[i][j]) ans++;
    }
  }
  cout << ans << endl;
}

