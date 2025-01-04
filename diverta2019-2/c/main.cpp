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

// A1...ANの整数が書かれている
// 以下の操作をN-1回繰り返して黒板にただ1つの整数が書かれているようにする
// 2個の整数x, yを選んで消し、新たに1個の整数x-yを書く
// 残る整数としてあり得る値の最大値と、その最大値を達成する操作列を求めよ
// ±A1, ±A2,,,みたいな感じにできる。ただし全部プラス、全部マイナスはできない
// マイナスにするのは一番小さい数、プラスにするのは一番大きい数
// それ以外の数は符号が+だったらプラスがいいし、-だったらマイナスがいい
// 操作の作り方
// マイナスにする群の1つからプラスのやつを引いていく(プラスが残り1個になるまで)
// その後、残ったプラスからマイナスの全部と作った数字を引いていけばよい
int main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  vector<int> positive, negative;
  // 一番大きいのと一番小さいのは予め詰めておく
  positive.push_back(A[A.size() - 1]);
  negative.push_back(A[0]);
  A.pop_back(); A.erase(A.begin());
  for(auto a : A) {
    if (a < 0) {
      negative.push_back(a);
    } else {
      positive.push_back(a);
    }
  }
  vector<pair<int, int>> ans_vec;
  int ans = negative.back();
  negative.pop_back();
  for(int i = 0; i < positive.size() - 1; i++) {
    ans_vec.push_back({ ans, positive[i] });
    ans -= positive[i];
  }
  ans_vec.push_back({ positive.back(), ans });
  ans = positive.back() - ans;
  for(int i = 0; i < negative.size(); i++) {
    ans_vec.push_back({ ans, negative[i] });
    ans = ans - negative[i];
  }
  cout << ans << endl;

  for(auto p : ans_vec) {
    cout << p.first << ' ' << p.second << endl;
  }
}
