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

// N * Mの長方形のマスから成っている
// 壁は# 壁でないのは.
// 壁マスをちょうど1マス壁でないマスに変える
// 壁でない2マスはすべて、上下左右に1マス動くことを繰り返し、村内の壁でないマスのみを取って互いに行き来可能である
// 全部つながってるっていうことか
// 変えるマスの候補はいくつあるか調べる
// 全探索の場合100 * 100で間に合いそう
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main() {
  int N, M; cin >> N >> M;
  vector<vector<char>> V(N, vector<char>(M));
  // 床の数
  int floor_cnt = 0;
  rep(i, N) rep(j, M) {
    cin >> V[i][j];
    if (V[i][j] == '.') floor_cnt++;
  }

  int ans = 0;
  rep(i, N) {
    rep(j, M) {
      // 壁でないマスはスキップ
      if (V[i][j] == '.') continue;

      // 一旦壁に置き換え
      V[i][j] = '.';
      queue<pair<int, int>> q;
      vector<vector<bool>> visited(N, vector<bool>(M, false));
      q.push({ i, j });
      visited[i][j] = true;
      int visit_cnt = 1;
      while(!q.empty()) {
        auto p = q.front(); q.pop();
        rep(k, 4) {
          int newX = p.first + dx[k], newY = p.second + dy[k];
          if(newX >= 0 && newX < N && newY >= 0 && newY < M) {
            if (!visited[newX][newY] && V[newX][newY] == '.') {
              visit_cnt++;
              visited[newX][newY] = true;
              q.push({ newX, newY });
            }
          }
        }
      }
      // 全床踏破してたら+1
      if(visit_cnt == (floor_cnt + 1)) ans++;
      // 戻す
      V[i][j] = '#';
    }
  }
  cout << ans << endl;
}

