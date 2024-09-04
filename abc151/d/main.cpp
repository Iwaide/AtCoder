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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int main() {
  int H, W; cin >> H >> W;
  vector<vector<char>> Maze(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> Maze[i][j];

  // 普通に全探索する
  int ans = 0;
  // 始点iから終点jまで。入れ替えても移動回数は変わらない
  int total = H * W;
  rep(i, total) {
    // (解説後): 始点だけ全探索して手数が一番大きいやつだけ残しても同じだった
    rep(j, total) {
      // 同一点の場合はスキップ
      if (i == j) continue;
      int startX = i / W, startY = i % W;
      int goalX = j / W, goalY = j % W;
      // 始点か終点が#マスのとき壁なのでスキップ
      if (Maze[startX][startY] == '#' || Maze[goalX][goalY] == '#') continue;

      
      vector<int> distance(total, -1);
      distance[i] = 0;
      // iからスタート
      queue<int> q; q.push(i);
      while(!q.empty()) {
        int p = q.front(); q.pop();
        // x, yを復元
        int x = p / W, y = p % W;
        rep(k, 4) {
          // 探索予定の点
          int newX = x + dx[k], newY = y + dy[k];
          if (newX >= 0 && newX < H && newY >= 0 && newY < W) {
            // 1次元に直したときの探索予定地
            int I = newX * W + newY;
            if (Maze[newX][newY] == '.' && distance[I] == -1) {
              distance[I] = distance[p] + 1;
              q.push(I);
            }
          } 
        }
      }
      // ゴールとの距離が大きいものを残していく
      chmax(ans, distance[j]);
    }
  }
  cout << ans << endl;
}

