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

// 蛇の待ち行列 列は空
// クエリがQ個与えられる
// 1. 1 l 長さlの蛇が列の末尾に追加される。もとの列が空の場合は0, そうでない場合は最後尾の蛇の頭の座標に最後尾の蛇の長さを加えた座標になる
// 2 列の先頭にいる蛇が列から抜ける、抜けた蛇の長さをmとして、列に残っているすべての蛇の頭の座標がmだけ減少する
// 3. 3 k 列の先頭から数えてk番目にいる蛇の頭の座標を出力せよ
int main() {
  int Q;
  cin >> Q;
  // 頭の座標、長さのペア
  deque<pair<ll, ll>> snakes;
  ll removed_length = 0, removed_count = 0;
  rep(i, Q) {
    int q; cin >> q;
    if (q == 1) {
      ll l;
      cin >> l;
      if (snakes.size() > 0) {
        auto last_snake = snakes.back();
        snakes.push_back({ last_snake.first + last_snake.second, l });
      } else {
        snakes.push_back({ 0, l });
      }
    } else if (q == 2) {
      auto first_snake = snakes.front();
      removed_length += first_snake.second;
      snakes.pop_front();
    } else if (q == 3) {
      int k; cin >> k; k--;
      cout << (snakes[k].first - removed_length) << endl;
    }
  }
}

