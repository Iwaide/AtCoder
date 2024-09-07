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

// H * Wのグリッドがある
// すべてのマスに壁が1個ずつ建てられている
// Q個のクエリ処理後に残っている壁の数を求める
// クエリ: Rq, Cqが与えられる
// (Rq, Cq)に爆弾を置いて壁を爆破する
// (Rq, Cq)に壁が存在する場合はその壁を破壊して処理を終了する
// (Rq, Cq)に壁が存在しない場合は(Rq, Cq)から上下左右に見て最初に現れる壁を破壊する
int main() {
  int H, W, Q; cin >> H >> W >> Q;

  // 壁が残ってるときtrue
  vector<vector<bool>> Grid(H, vector<bool>(W, true));
  // 壁の残存数
  int ans = H * W;
  int minU = H, minD = 0, minL = W, minR = 0;
  rep(_, Q) {
    int R, C; cin >> R >> C;
    R--; C--;
    // (Rq, Cq)に壁が存在しているとき
    if (Grid[R][C]) {
      Grid[R][C] = false;
      chmin(minU, R - 1);
      chmin(minD, R + 1);
      chmin(minL, C - 1);
      chmin(minR, C + 1);
      ans--;
      continue;
    }

    // 上方向への爆破
    if (R > 0) {
      int r = min(minU, R - 1);
      if (r >= 0 && Grid[r][C]) {
        Grid[r][C] = false;
        chmin(minU, r);
        break;
      } 
    }

    // 下方向への爆破
    if (R < H - 1) {
      int r = min(minD, R + 1);
      if (r >= 0 && Grid[r][C]) {
        Grid[r][C] = false;
        chmin(minU, r);
        break;
      } 
    }

    // 左
    if (C > 0) {
      for(int i = C - 1; i >= 0; i--) {
        if (Grid[R][i]) {
          Grid[R][i] = false;
          ans--;
          break;
        }
      }
    }
    // 右
    if (C < W - 1) {
      for(int i = C + 1; i < W; i++) {
        if (Grid[R][i]) {
          Grid[R][i] = false;
          ans--;
          break;
        }
      }
    }
  }
  cout << ans << endl;
}
