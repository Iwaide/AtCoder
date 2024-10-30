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

// 長さNの正整数列L(L1, L2 ... LN), R(R1, R2 ... RN)と整数Mが与えられる
// 以下の条件を共に満たす整数の組(l, r)を求めよ
// 1 <= l　<= r <= M
// すべての 1 <= i <= Nに対して区間[l, r]は[Li, Ri]を完全には含まない
// N, M <= 2 * 10^5
// L = 1, 3
// R = 2, 4
// M = 4のとき
// l,rの取りうる値は(1, 1),(1, 2)...(4, 4)まであるが 
// i=1 (1, 2)と i=2(3,4)を完全に含まないのは
// (1, 1) (2, 2) (2, 3) (3, 3) (4, 4)のみ
// int main() {
//   int N, M;
//   cin >> N >> M;
//   vector<int> Lmin(200001, M + 1), Rmax(200001, 0);
//   rep(i, N) {
//     int L, R; cin >> L >> R;
//     chmin(Lmin[L], R);
//     chmax(Rmax[R], L);
//   }
//   rep2(i, 1, 200001) {
//     chmax(Rmax[i], Rmax[i - 1]);
//   }
//   for(int i = 200000; i >= 0; i--) {
//     chmin(Lmin[i - 1], Lmin[i]);
//   }
//   ll ans = 0;
//   for (int l = 1; l <= M; l++) {
//     int min_r = max(l, Rmax[l] + 1);
//     int max_r = Lmin[l] - 1;

//     // `min_r` から `max_r` の範囲内で条件を満たす r があれば、その数を加算
//     if (min_r <= max_r) {
//       ans += (max_r - min_r + 1);
//     }
//   }

//   cout << ans << endl;
// }

int main() {
  int N, M;
  cin >> N >> M;
  // Rmaxはrを固定したときのlの最大値
  vector<int> Lmax(200001, 0);
  rep(i, N) {
    int L, R; cin >> L >> R;
    chmax(Lmax[R], L);
  }
  // たとえば、Rが7のときでLmaxが5, Rが8のときに何もない時
  // (5, 8)が含んではいけない最小範囲になるのでLmax[8]はLmax[7]から引き継いで5になる。
  rep2(i, 1, 200001) chmax(Lmax[i], Lmax[i - 1]);

  ll ans = 0;
  // rを右にずらしていく
  rep2(r, 1, M + 1)  {
    int l = Lmax[r];
    ans += r - l;
  }
  cout << ans << endl;
}
