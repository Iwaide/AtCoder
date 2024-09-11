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

// (0, 0)から(X, Y)に移動
// 障害物は(xi, yi)にある
// xi, yiは|200|以下
// |1|の座標を取るには、3必要 1 * 2 + 1
// -1 = 1, 0 = 2, 1 = 3
// -200 = 0, 0 = 200, .... 200 = 400
// ↑これだめで、外周を通ることを想定しないといけないので、|201|のGridを作る必要があった
int dx[6] = { 1, 0, -1, 1, -1, 0 };
int dy[6] = { 1, 1, 1, 0, 0, -1 };
int main() {
  int N, X, Y; cin >> N >> X >> Y;
  int len = 201 * 2 + 1;
  // trueのとき壁
  vector<vector<bool>> Grid(len, vector<bool>(len, false));

  rep(i, N) {
    int x, y; cin >> x >> y;
    x += 201; y += 201;
    Grid[x][y] = true;
  }

  queue<pair<int, int>> q;
  q.push({ 201, 201 });
  vector<vector<int>> ans(len, vector<int>(len, -1));
  ans[201][201] = 0;
  while(!q.empty()) {
    auto p = q.front(); q.pop();
    rep(i, 6) {
      int x = p.first + dx[i], y = p.second + dy[i];
      if (x >= 0 && x < len && y >= 0 && y < len) {
        if (ans[x][y] == -1 && !Grid[x][y]) {
          ans[x][y] = ans[p.first][p.second] + 1;
          q.push({ x, y });
        }
      }
    }
  }
  // X, Yも201増やす
  X += 201, Y += 201;
  cout << ans[X][Y] << endl;
}
