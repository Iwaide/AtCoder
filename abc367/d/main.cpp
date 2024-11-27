#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> r={0};
  // 累積和の余りを求める
  rep(i, 2 * n) {
    r.push_back((r.back() + a[i % n]) % m);
  }
  vector<int> b(m, 0);
  // 0, N - 1までのあまりの頻度を求めておく
  rep(i, n) b[r[i]]++;

  ll res = 0;
  // Nから 2 * N - 1までについて計算する
  // s < tのとき Rs = Rt つまり RN + s = RN + t
  // s > tのとき Rs = RN + t だから i = N,.. 2N - 1について
  // Ri - N + 1 ,,, Ri - 1の中にRiと等しい要素がどれだけあるかカウントする
  for(int i = n; i < 2 * n; i++) {
    // B[Ri - N]から1引く
    // Bはi　- N + 1からi-1までの頻度を管理する配列となる
    b[r[i-n]]--;
    // r[i]の頻度を足す
    res += b[r[i]];
    // B[R[i]]に1加算する Bはi - N + 1からiまでの頻度を管理する配列となる
    b[r[i]]++;
  }
  cout << res << endl;
}
