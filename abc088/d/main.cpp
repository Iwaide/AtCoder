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

// ゴールに到達可能でありつつ、最大埋められる数
// 最短経路にして、あと全部埋めれば良さそう
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> G(H, vector<char>(W));
  int black_cnt = 0;
  rep(i, H) {
    rep(j, W) {
      cin >> G[i][j];
      if(G[i][j] == '#') black_cnt++;
    } 
  }
  vector<vector<int>> passed(H, vector<int>(W, -1));
  queue<pair<int, int>> q;
  int dx[4] = { 0, 1, 0, -1 };
  int dy[4] = { -1, 0, 1, 0 };
  q.push(make_pair(0, 0));
  passed[0][0] = 1;
  while(!q.empty()) {
    auto p = q.front(); q.pop();

    rep(i, 4) {
      int x = p.first + dx[i], y = p.second + dy[i];
      if (x >= 0 && x < H && y >= 0 && y < W) {
        if (G[x][y] != '#' && passed[x][y] == -1) {
          passed[x][y] = passed[p.first][p.second] + 1;
          q.push(make_pair(x, y));
        }
      }
    }
  }
  if (passed[H - 1][W - 1] == -1) {
    cout << -1 << endl;
    return 0;
  }
  int res = H * W - black_cnt - passed[H-1][W-1];
  cout << res << endl;
}
