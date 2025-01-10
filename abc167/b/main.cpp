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

// 1が書かれたカードがA枚
// 0が書かれたカードがB枚
// -1が書かれたカードがC枚
// ここからK枚選んで取るとき、取ったカードに書かれた数の和としてあり得る値の最大値はいくつか
int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  // 1のカード枚数
  ll ans = min(K, A);
  K -= ans;
  // 0のカード枚数
  K -= min(K, B);
  cout << ans - min(K, C) << endl;
}

