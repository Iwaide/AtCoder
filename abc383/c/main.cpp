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

// H行W列のマス目
// Sijが#のとき壁、.のときは床、Hなら加湿器が置かれた床
// ある加湿器から壁を通らず上下左右にD回以下の移動で辿り着けるますが加湿される
// 加湿器の置かれているマスは必ず加湿されている
// 加湿されている床のマスの個数を求めよ
// 四方向の移動
vector<pair<int, int>> dxy = {
  { -1, 0 },
  { 0, 1 },
  { 1, 0 },
  { 0, -1 }
};

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<vector<char>> S(H, vector<char>(W));
  // BFS用のキューと訪問管理
  queue<pair<int, int>> q;
  vector<vector<int>> visited(H, vector<int>(W, -1));

  rep(i, H) rep(j, W) {
    cin >> S[i][j];
    if (S[i][j] == 'H') {
      q.push({i, j});
      visited[i][j] = 0;
    }
  }

  // BFSを実行
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    // 四方向に移動
    for (auto [dx, dy] : dxy) {
      int nx = x + dx, ny = y + dy;
      if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
        if (visited[nx][ny] == -1 && S[nx][ny] == '.') {
          visited[nx][ny] = visited[x][y] + 1;
          if (visited[nx][ny] < D) { // 距離制限を超えない場合のみ探索を続行
            q.push({ nx, ny });
          }
        }
      }
    }
  }

  int ans = 0;
  rep(i, H) rep(j, W) if (visited[i][j] != -1 && visited[i][j] <= D) ans++;

  cout << ans << endl;
}
