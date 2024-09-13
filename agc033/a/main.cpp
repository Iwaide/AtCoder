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

// をqueに詰めておいて侵食させれば良さそう
int main() {
  int dx[4] = { -1, 0, 1, 0 };
  int dy[4] = { 0, 1, 0, -1 };

  int H, W; cin >> H >> W;
  vector<vector<char>> Grid(H, vector<char>(W));
  vector<vector<int>> distance(H, vector<int>(W, -1));
  queue<pair<int, int>> q;
  rep(i, H) {
    rep(j, W) {
      cin >> Grid[i][j];
      if (Grid[i][j] == '#') {
        q.push({ i, j });
        distance[i][j] = 0;
      }
    }
  }
  while(!q.empty()) {
    auto p = q.front(); q.pop();
    rep(i, 4) {
      int x = p.first + dx[i], y = p.second + dy[i];
      if (x >= 0 && x < H && y >= 0 && y < W) {
        if (Grid[x][y] == '.' && distance[x][y] == -1) {
          Grid[x][y] = '#';
          distance[x][y] = distance[p.first][p.second] + 1;
          q.push({ x, y });
        }
      }
    }
  }
  int ans = 0;
  rep(i, H) rep(j, W) chmax(ans, distance[i][j]);

  cout << ans << endl;
}
