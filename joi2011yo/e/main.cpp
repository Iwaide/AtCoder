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

// 1への最短ルート、1から2への最短…でやっていけば良さそう
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
  int H, W, N; cin >> H >> W >> N;
  vector<vector<char>> Grid(H, vector<char>(W));
  pair<int, int> start;
  // 工場番号そのまま入れるのでN+1
  vector<pair<int, int>> factories(N + 1);
  rep(i, H) {
    rep(j, W) {
      cin >> Grid[i][j];
      if (Grid[i][j] == 'S') {
        start = { i, j };
      } else if (Grid[i][j] != 'X' && Grid[i][j] != '.') {
        int num = Grid[i][j] - '0'; 
        factories[num] = { i, j };
      } 
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    auto factory = factories[i];
    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<int>> distance(H, vector<int>(W, -1));
    distance[start.first][start.second] = 0;
    while(!q.empty()) {
      auto p = q.front(); q.pop();
      rep(j, 4) {
        int x = p.first + dx[j], y = p.second + dy[j];
        if (x >= 0 && x < H && y >= 0 && y < W) {
          if (distance[x][y] == -1 && Grid[x][y] != 'X') {
            distance[x][y] = distance[p.first][p.second] + 1;
            if (factory.first == x & factory.second == y) {
              break;
            } else {
              q.push({ x, y });
            }
          }
        }
      }
    }
    // 工程足して、startの位置変える
    ans += distance[factory.first][factory.second];
    start = { factory.first, factory.second };
  }
  cout << ans << endl;
}

