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

// N個のマスが一列に並んでいる
// M個のマスに石が入っており、マスXiにはAi個の石が入っている
// マスiから石をマスi+1に1つ移動させる、を繰り返したときの必要な操作回数の最小値
// どのマスに何個石があるか、ではなく石の位置について考える
// (1, 3) (4, 2)みたいなとき、 { 1, 1, 1, 4, 4 }みたいな状態だとする
// この数字について1足して1, 2, ...Nの数列を作ることを考える
// すべてが0のとき 必要な操作回数は (N + 1) * N / 2
// Mについて見ていくと例えば(1, 3)だったとき、{ 1, 1, 1 } だから1 * 3回分あらかじめやってあることになる
// また成立しないケースについて、石の数がマス目と等しくないときと、位置がiよりも大きいときが挙げられる(マスの位置を減らすことはできないため)
int main() {
  ll N, M, sum = 0; cin >> N >> M;
  vector<pair<ll, ll>> stone(M);
  rep(i, M) cin >> stone[i].first, stone[i].first--;
  rep(i, M) cin >> stone[i].second, sum+= stone[i].second;
  // 石の数がマス目と等しくないとき
  if (sum != N) {
    cout << -1 << endl;
    return 0;
  }

  sort(all(stone));
  ll index = 0, ax_sum = 0;

  for(auto [place, num] : stone) {
    // 石の位置がマスの位置より大きいとき
    if (place > index) {
      cout << -1 << endl;
      return 0;
    }
    index += num;
    ax_sum += place * num;
  }
  // 0始まりなので、0...N-1, (0 + N) * (N - 1) / 2
  cout << N * (N - 1) / 2 - ax_sum << endl;
}

