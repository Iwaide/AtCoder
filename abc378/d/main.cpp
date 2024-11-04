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

int K, H, W;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<char>> Grid;
vector<vector<bool>> visited;
int dfs(int i, int j, int k) {
  if (k == K) return 1;

  int ans = 0;
  // 上下左右に移動
  rep(l, 4) {
    int x = i + dx[l], y = j + dy[l];
    if (x >= 0 && x < H && y >=0 && y < W) {
      if (!visited[x][y] && Grid[x][y] == '.') {
        visited[x][y] = true;
        ans += dfs(x, y, k + 1);
        visited[x][y] = false;
      }
    }
  }
  return ans;
}

// マス.#
// 空きマスを種っぱtうして、上下左右に移動をK回行う方法で
// 障害物のあるマスを通らず、同じマスを2回以上通らないようなものの個数
int main() {
  cin >> H >> W >> K;
  Grid.resize(H, vector<char>(W));
  visited.resize(H, vector<bool>(W, false));
  rep(i, H) rep(j, W) cin >> Grid[i][j];

  int ans = 0;
  // 全マスに対して深さ優先すれば良さそう
  rep(i, H) {
    rep(j, W) {
      if (Grid[i][j] == '#') continue;
      visited[i][j] = true;
      ans += dfs(i, j, 0);
      visited[i][j] = false;
    }
  }
  cout << ans << endl;
}

