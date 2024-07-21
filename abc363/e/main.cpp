#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MAX_H 1000
#define MAX_W 1000
#define MAX_Y 100000

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  // Y年分のキューを用意する
  vector<queue<int>> q(MAX_Y + 1);
  vector<vector<int>> a(h, vector<int>(w));
  // 内陸にあるかどうか
  vector<vector<bool>> inland(h, vector<bool>(w));
  // 全マスの合計
  int ans = h*w;

  rep(i, h) {
    rep(j, w) {
      cin >> a[i][j];
      inland[i][j] = true;
      if (i == 0 || i == (h - 1) || j == 0 || j == (w - 1)) {
      //   // Y年後に探索すべき海に面したマス
        q[a[i][j]].push(w * i + j);
        inland[i][j] = false;
      }
    }
  }

  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {1, -1, 0, 0};

  // // n年後までシミュレート
  for(int i = 1; i <= n; i++) {
    // 普通に取り出すとコピーされて新しくpushしたのが反映されないので参照でとる
    queue<int> &que = q[i];
    while(!que.empty()) {
      ans--;
      int z = que.front(); que.pop();
      // 座標を復元
      int x = z / w; int y = z % w;
      // 上下左右4マスを見る
      for(int j = 0; j < 4; j++) {
        int new_x = x + dx[j], new_y = y + dy[j];
        // 上下左右4マスが島内であれば
        if ((new_x >= 0) && (new_x < h) && (new_y >= 0) && (new_y < w)) {
          // 隣接マスが内陸だったとき、キューに入ってるのは海面なのであらたに海に面したということになる
          if(inland[new_x][new_y]) {
            int nextY = max(a[new_x][new_y], i);
            // 新たに探索範囲に加える
            q[nextY].push(w * new_x + new_y);
            inland[new_x][new_y] = false;
          }
        }
      }
    }
    cout << ans << endl;
  }
}

