#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline ll div_ceil(T a,T b) { return (a+b-1)/b; }

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


// ある製品には1...N個の工程が必要
// 各工程iについてそれを処理する2種類の機械、Si, Tiが売られている
// Si: Ai個/日、Pi円
// Ti: Bi個/日、Qi円
// 予算がX円のとき達成可能な製造能力の最大値
// 機械Siのほうがコスパ悪いとき、機械Siの導入台数は必ずBi台未満になる
// Bi台のSiによる製造能力(Ai * Bi)はAi台の機械Tiによる製造能力(Bi * Ai)で代替できるから
int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> A(n), P(n), B(n), Q(n);
  rep(i, n) {
    cin >> A[i] >> P[i] >> B[i] >> Q[i];
  }
  ll l = -1, r = x * 100 + 1;
  while(r - l > 1) {
    ll mid = (l + r) / 2;
    bool can = true;
    // かかる金額
    ll sum = 0;

    // 各工程について
    rep(i, n) {
      // aはTiのほうがコスパ悪いときにかかる最小金額
      // bはSiのほうがコスパ悪いときにかかる最小金額
      ll a = 1e9, b = 1e9;
      // Tiのほうがコスパ悪いとき、TiはAi台未満になるはずなので全探索する
      rep(j, A[i]) {
        ll TiSum = j * Q[i];
        ll SiSum = div_ceil(max(0LL, mid - B[i] * j), A[i]) * P[i];
        chmin(a, SiSum + TiSum);
      }
      // Siのほうがコスパ悪い時SiはBi台未満になるはず
      rep(j, B[i]) {
        ll SiSum = j * P[i];
        ll TiSum = div_ceil(max(0LL, mid - A[i] * j), B[i]) * Q[i];
        chmin(b, SiSum + TiSum);
      }
      sum += min(a, b);
      if (sum > x) {
        can = false;
        break;
      }
    }
    if (can) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
}
