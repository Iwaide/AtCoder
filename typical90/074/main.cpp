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

// a, b, cからなる長さNの文字列Sが表示されている
// Si = bであるiを1つ選び、Siをaに変更したあと、S1,,Si-1を変化させる
// Si = cであるiを1つ選び、Siをbに変更したあと、S1,,,Si-1を変化させる
// 変化させる、とはもともとa -> b, b -> c, c ->aにすること
// 最大で何回行えるか
int main() {
  int N; cin >> N;
  vector<ll> A;
  rep(i, N) {
    char c; cin >> c;
    A.push_back(c - 'a');
  }
  ll ans = 0;
  rep(i, N) {
    ans += A[i] * (1LL << (i));
  }
  cout << ans << endl;
}

