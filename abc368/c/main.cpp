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

// きったないので後で直す
ll solve(ll T) {
  if (current == N) {
    return T;
  }

  ll loop_cnt = 0;
  if (H[current] >= 5) {
    loop_cnt = H[current] / 5LL;
    H[current] -= loop_cnt * 5LL;
  }

  vector<int> mod(3);
  if (T % 3 == 0) {
    mod = vector<int> { 3, 1, 1 };
  } else if (T % 3 == 1) {
    mod = vector<int> { 1, 1, 3 };
  } else {
    mod = vector<int> { 1, 3, 1 };
  }

  ll tmpT = 0;
  while(H[current] > 0) {
    H[current] -= mod[tmpT % 3];
    tmpT++;
  }
  T += (tmpT + loop_cnt * 3);

  if (H[current] <= 0) {
    current += 1;
  }
  return solve(T);
}

// N人の敵が並んでいる、前からi番目の敵の体力はHi
// 0で初期化された変数Tを使い、すべての敵の体力が0以下になるまで行動を繰り返す
// Tを1増やす、その後体力が1である最も前の敵を攻撃する、
// このとき、Tが3の倍数ならばその敵の体力は3減り、そうでないなら1減る
int main() {
  cin >> N;
  H.resize(N);
  rep(i, N) cin >> H[i];

  ll ans = solve(1);
  cout << --ans << endl;
}

