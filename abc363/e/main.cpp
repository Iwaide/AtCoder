#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MAX_H 1000
#define MAX_W 1000
#define MAX_Y 100000

int main() {
  int H, W, Y; cin >> H >> W >> Y;
  vector<vector<int>> A(H, vector<int>(W));
  // Y年時に調べるところ
  vector<queue<int>> ques(MAX_Y + 1, queue<int>());
  // 内陸にあるかどうか
  vector<vector<bool>> inland(H, vector<bool>(W, true));
  rep(x, H) { 
    rep(y, W) {
      cin >> A[x][y];
      if (x == 0 || x == (H - 1) || y == 0 || y == (W - 1)) {
        ques[A[x][y]].push(x * W + y);
        inland[x][y] = false;
      }
    }
  }
  int dx[4] = { 0, 1, 0, -1 };
  int dy[4] = { 1, 0, -1, 0 };
  int ans = H * W;
  for(int i = 1; i <= Y; i++) {
    queue<int> &que = ques[i];
    while(!que.empty()) {
      ans--;
      int z = que.front(); que.pop();
      int x = z / W, y = z % W;
      rep(j, 4) {
        int newX = x + dx[j], newY = y + dy[j];
        if (newX >= 0 && newX < H && newY >= 0 && newY < W) {
          if (inland[newX][newY]) {
            int sunk_year = max(A[newX][newY], i);
            ques[sunk_year].push(newX * W + newY);
            inland[newX][newY] = false;
          }
        }
      }
    }
    cout << ans << endl;
  }
}

