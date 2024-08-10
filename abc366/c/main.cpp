#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// 空の袋からスタート。クエリがQ
// 1 x: 整数xが書かれたボールを1つ袋に入れる
// 2 x: 整数xが書かれたボールを１つ袋の中から取り出しと外に捨てる
// 3: 袋の中にあるボールに書かれている整数の種類数を出力する
int main() {
  int Q; cin >> Q;
  map<int, int> bag;
  rep(i, Q) {
    int query; cin >> query;
    if (query == 1) {
      int x; cin >> x;
      bag[x] += 1;
    } else if (query == 2) {
      int x; cin >> x;
      if (bag[x] == 1) {
        bag.erase(x);
      } else {
        bag[x] -= 1;
      }
    } else {
      // query == 3のとき
      cout << bag.size() << endl;
    }
  }
}

