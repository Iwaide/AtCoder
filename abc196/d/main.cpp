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

// 縦(2 * 1)、横(1*2)、1マス(1*1)、を全探索する？
// 一回愚直に書いてみるか
int H, W, A, B;
vector<vector<bool>> T;
int solve(int a, int b) {

  // 左上から空きますを探す
  int x = 0, y = 0;
  int res = 0;
  while(T[x][y]) {
    x++;
    // 縦終わったら横の列にうつる
    if (x >= H) {
      x = 0;
      y++;
    }
    // 横も一杯になったら終わり
    if (y >= W) {
      if (a == A && b == B) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  int ans = 0;
  // 縦のとき
  if (x + 1 < H && !T[x+1][y] && a < A) {
    T[x][y] = T[x+1][y] = true;
    ans += solve(a + 1, b);
    T[x][y] = T[x+1][y] = false;
  }
  // // 横のとき
  if (y + 1 < W && !T[x][y+1] && a < A) {
    T[x][y] = T[x][y+1] = true;
    ans += solve(a + 1, b);
    T[x][y] = T[x][y+1] = false;
  }
  if (b < B) {
    T[x][y] = true;
    ans += solve(a, b + 1);
    T[x][y] = false;
  }
  return ans;
}

int main() {
  cin >> H >> W >> A >> B;
  T = vector<vector<bool>>(H, vector<bool>(W, false));
  int ans = solve(0, 0);

  cout << ans << endl;
}

