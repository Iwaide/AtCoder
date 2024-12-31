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

int GCD(int x, int y) {
  if (y == 0) {
    return x;
  } else {
    return GCD(y, x % y);
  }
}

// N個のボールが入っていてi番目には整数Aiが書かれている
// 箱から2つのボールを取り出し、その2つのボールに書かれている差の絶対値を書いた新しいボールと一緒に箱に戻す
// Kの書かれたボールが箱に入っている状態にできるかを判定せよ
// 例えば2個のケース(a, b)(a > b)から考えると、GCD(a, b) = GCD(a - b, b)が成り立つ
// つまりa-bを繰り返していった結果はaとbの最大公約数となる
// a以下でGCD(a,b)の倍数はすべて作れる
// これをN個について考えると、GCD(A1....AN)が作れて、
// maxAi以下かつGCD(A1,,,,AN)の整数はすべて作れるということになる
int main() {
  int N, K;
  cin >> N >> K;
  int g = 0, max_a = 0;
  rep(i, N) {
    int ai; cin >> ai;
    chmax(max_a, ai);
    g = GCD(g, ai);
  }
  if (K <= max_a && K % g == 0) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}

