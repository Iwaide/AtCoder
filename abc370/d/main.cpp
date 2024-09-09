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

int main() {
  int H, W, Q; cin >> H >> W >> Q;
  // g1[i]はi行目に残っている壁の位置を列番号で持っている
  // g2[j]はj列目に残っている壁の位置を行番号で持っている
  vector<set<int>> g1(H), g2(W);
  rep(i, H) {
    rep(j, W) {
      g1[i].insert(j);
      g2[j].insert(i);
    }
  }

  // (i, j)を2つの配列から消す無名関数
  auto erase = [&](int i, int j) { g1[i].erase(j), g2[j].erase(i); };
  while(Q--) {
    int R, C; cin >> R >> C;
    R--; C--;
    // その座標に壁がある == 配列のsetの中に座標がある
    if (g1[R].count(C)) {
      erase(R, C);
      continue;
    }

    // 上
    // lower_boundでとってきたiteratorの1個前が爆破される
    {
      auto it = g2[C].lower_bound(R);
      // 一番最初の要素のときは、爆弾より上に壁が無いということなのでスキップする
      if (it != begin(g2[C])) erase(*prev(it), C);
    }

    // 下
    {
      auto it = g2[C].lower_bound(R);
      if (it != end(g2[C])) erase(*it, C);
    }

    // 左
    {
      auto it = g1[R].lower_bound(C);
      if (it != begin(g1[R])) erase(R, *prev(it));
    }

    // 右
    {
      auto it = g1[R].lower_bound(C);
      if (it != end(g1[R])) erase(R, *it);
    }
  }
  int ans = 0;
  rep(i, H) ans += g1[i].size();
  cout << ans << endl;
}
