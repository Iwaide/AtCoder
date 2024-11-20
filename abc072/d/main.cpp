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

// 1, 2..Nからなる順列p1, p2,,, pNが与えられる
// 操作; 順列で隣り合う2つの数を選んでスワップする
// 任意の1 <= i <= Nに対して pi!=iとなるようにしたい
// 必要な操作の最小回数を求めろ
// 左から順に見ていって=iだったらswapでいい気がする
// 手戻りが発生するケースはp1p1, p2があってp1を動かしたいとき、p2がp1の位置で=iになることだが
// p1..pNはバラバラの数なのでそれはない
// pNのときだけ気をつければいいか
int main() {
  int N; cin >> N;
  vector<int> p(N);
  rep(i, N) cin >> p[i];

  int ans = 0;
  rep(i, N) {
    if (i + 1== p[i] && i != N - 1) {
      ans++;
      swap(p[i], p[i + 1]);
    }
    if (i == N - 1 && N == p[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}

