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

// N枚のカードの山、上からi枚目には整数Aiが書かれている
// 操作を繰り返して残ったカードに書かれた値が互いに異なるようにしたい
// 最大で何枚のカードを残せるか
// 操作: カードの山から任意の3枚を抜き出す。
// 最大のカードと最小のカードを消す、残った1枚をカードの山に戻す
int main() {
  int N; cin >> N;
  vector<int> A(N);
  map<int, int> m;
  rep(i, N) {
    int Ai; cin >> Ai;
    m[Ai]++;
  }
  // 3枚同じのとき2枚消せる
  // そうでないとき
  // 1. 他にも同じ2枚があるとき両方を消せる
  // 2. ないとき重複の2枚から1枚と他の適当な数字から1枚減らす
  // 結局2枚同士のペアが偶数あるか、奇数あるか、で最終枚数変わってきそう
  // ペアが偶数のとき種類分残せる、奇数のとき-1分残せる
  int var_cnt = 0, pair_cnt = 0;
  for(auto p : m) {
    // 種類カウントしておく
    var_cnt++;
    if (p.second <= 1) continue;
    // 奇数枚(3,5..枚)のとき2枚ずつ削っていけば良くてペアにならない
    // 偶数枚のときペアが残る
    if (p.second % 2 == 0) pair_cnt++;
  }
  if (pair_cnt % 2) {
    cout << var_cnt - 1 << endl;
  } else {
    cout << var_cnt << endl;
  }
}

