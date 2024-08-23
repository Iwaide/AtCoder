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
int H, W, goalX, goalY;
vector<vector<char>> F;
vector<vector<bool>> used;

int solve(int k, int x, int y, int ddx, int ddy) {
  if (k > 0 && x == goalX && y == goalY) {
    return k;
  }

  int dx[4] = { 0, 1, 0, -1 };
  int dy[4] = { -1, 0, 1, 0 };

  int res = -1;
  rep(i, 4) {
    // 元来た方向からは戻れない
    if (ddx == -1 * dx[i] && ddy == -1 * dy[i] ) {
      continue;
    }
    int newX = x + dx[i], newY = y + dy[i];
    if (newX >= 0 && newX < H && newY >= 0 && newY < W) {
      if (F[newX][newY] == '.' && !used[newX][newY]) {
        used[newX][newY] = true;
        chmax(res, solve(k + 1, newX, newY, dx[i], dy[i]));
        used[newX][newY] = false;
      }
    }
  }
  return res;
}

int main() {
  cin >> H >> W;
  F = vector<vector<char>>(H, vector<char>(W));
  used = vector<vector<bool>>(H, vector<bool>(W, false));
  rep(i, H) rep(j, W) {
    cin >> F[i][j];
  }
  int ans = -1;
  rep(i, H) {
    rep(j, W) {
      if (F[i][j] == '.') {
        goalX = i, goalY = j;
        chmax(ans, solve(0, i, j, 0 , 0));
      }
    }
  }
  cout << ans << endl;
}

