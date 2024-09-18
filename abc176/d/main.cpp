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

// H, Wマスの迷路 #が壁.が道
// (Ch, Cw)に魔法使いがいる
// 移動方法A: 現在マスの上下左右に隣接する道
// 移動B: 現在いるマスを中心とする5*5の範囲内にある道のマスへワープ魔法で移動
// (Dh, Dw)に移動するにはワープを最低何回使う必要があるか
// ある地点から動けるマスとワープできるマスを取っておいて、
// とりあえず移動で前埋めしてからqueが空にになったら次のqueに行くみたいな感じにする
// 2.5 * 10^7ぐらい？まぁいけそうな気はする
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
  int H, W, Ch, Cw, Dh, Dw;
  cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
  // 1始まりなので調整
  Ch--, Cw--, Dh--, Dw--;
  vector<vector<char>> Maze(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> Maze[i][j];

  // [ワープ回数] = queue
  // 0-1BFSでやってみる
  vector<queue<pair<int, int>>> ques(2);
  // 行ったところ。中身をワープ回数にしておく
  vector<vector<int>> visited(H, vector<int>(W, -1));
  visited[Ch][Cw] = 0;
  ques[0].push({ Ch, Cw });
  int warp_cnt = 0;
  while(!ques[warp_cnt % 2].empty()) {
    auto &q = ques[warp_cnt % 2];
    int px, py;
    tie(px, py) = q.front(); q.pop();
    // 上下左右移動
    rep(j, 4) {
      int x = px + dx[j], y = py + dy[j];
      if (x >= 0 && x < H && y >= 0 && y < W) {
        if (Maze[x][y] == '.') {
          if ((visited[x][y] == -1 || visited[x][y] > warp_cnt)) {
            // ワープ回数だけ入れたい
            visited[x][y] = warp_cnt;
            q.push({x, y});
          }
        }
      }
    }
    // ワープ移動
    for(int k = -2; k < 3; k++) {
      for(int l = -2; l < 3; l++) {
        if (k == 0 && l == 0) continue;

        int wx = px + k, wy = py + l;
        if (wx >= 0 && wx < H && wy >= 0 && wy < W) {
          if (Maze[wx][wy] == '.' && (visited[wx][wy] == -1)) {
            visited[wx][wy] = warp_cnt + 1;
            ques[(warp_cnt + 1) % 2].push({wx, wy});
          }
        }
      }
    }
    if (ques[warp_cnt % 2].empty()) {
      warp_cnt++;
    }
  }
  cout << visited[Dh][Dw] << endl;
}

