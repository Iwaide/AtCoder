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

// H行W列のグリッド
// スタート、ゴール、空きマス、障害物マスがある
// 縦移動と横移動を1回ずつ交互に行わなければならない
// 最初縦で進んだパターンと横で進んだパターンを行けば良さそう？
vector<vector<pair<int, int>>> dxy = {
  {
    { -1, 0 },
    { 1, 0 }
  },
  {
    { 0, -1 },
    { 0, 1 },
  }
};

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> Grid(H, vector<char>(W));
  pair<int, int> start, goal;
  rep(i, H) rep(j, W) {
    cin >> Grid[i][j];
    if (Grid[i][j] == 'S') start = { i, j };
    if (Grid[i][j] == 'G') goal = {i, j };
  }

  int ans = INT_MAX;
  // 横移動から始めたとき
  vector<vector<int>> moved(H, vector<int>(W, -1));
  // 0縦、1横移動 x, y
  queue<tuple<int, int, int>> q;
  q.push({ 0, start.first, start.second });
  moved[start.first][start.second] = 0;
  while(!q.empty()) {
    auto p = q.front(); q.pop();
    int type = get<0>(p), x = get<1>(p), y = get<2>(p);
    rep(i, 2) {
      int dx = dxy[type][i].first + get<1>(p), dy = dxy[type][i].second + get<2>(p);
      if (dx >= 0 && dx < H && dy >= 0 && dy < W) {
        if (moved[dx][dy] == -1) {
          if (Grid[dx][dy] == 'G') {
            chmin(ans, moved[x][y] + 1);
          } else if (Grid[dx][dy] == '.') {
            moved[dx][dy] = moved[x][y] + 1;
            q.push({ (type + 1) % 2, dx, dy });
          }
        }
      }
    }
  }
  // 一旦初期化
  moved = vector<vector<int>>(H, vector<int>(W, -1));
  q.push({ 1, start.first, start.second });
  moved[start.first][start.second] = 0;

  while(!q.empty()) {
    auto p = q.front(); q.pop();
    int type = get<0>(p), x = get<1>(p), y = get<2>(p);
    rep(i, 2) {
      int dx = dxy[type][i].first + get<1>(p), dy = dxy[type][i].second + get<2>(p);
      if (dx >= 0 && dx < H && dy >= 0 && dy < W) {
        if (moved[dx][dy] == -1) {
          if (Grid[dx][dy] == 'G') {
            chmin(ans, moved[x][y] + 1);
          } else if (Grid[dx][dy] == '.') {
            moved[dx][dy] = moved[x][y] + 1;
            q.push({ (type + 1) % 2, dx, dy });
          }
        }
      }
    }
  }
  if (ans == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

