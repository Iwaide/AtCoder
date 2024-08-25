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
vector<ll> H;
int N;
int current = 0;

// N人の敵が並んでいる、前からi番目の敵の体力はHi
// 0で初期化された変数Tを使い、すべての敵の体力が0以下になるまで行動を繰り返す
// Tを1増やす、その後体力が1である最も前の敵を攻撃する、
// このとき、Tが3の倍数ならばその敵の体力は3減り、そうでないなら1減る
int main() {
  cin >> N;
  H.resize(N);
  rep(i, N) cin >> H[i];
  ll T = 0;

  for(auto h : H) {
    ll loop_cnt = h / 5;
    T += loop_cnt * 3;
    h -= loop_cnt * 5;
    while(h > 0) {
      T += 1;
      if (T % 3 == 0) {
        h -= 3;
      } else {
        h -= 1;
      }
    }
  }

  cout << T << endl;
}

