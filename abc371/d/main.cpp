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

// 数直線状にN個の村がある。i番目の村は座標Xi, Pi人の村
// 座標Li, Ri感の村人の人数の総数を求める
// なんか普通に累積和の問題っぽい？と思ったけど10^9か…2secだと10^8
// mapでやってやればいいかも？
// 実装がわからんかった
// map自体はキーがマイナスでも大丈夫だし、mapで累積和取るのがよかった
// x[i]は小さい順に並んでるので、特にsortする必要はない
// あとは取り出し方
// { 0, 1 } , { 1, 2 }, { 3, 3 } , { 5, 4 }があるとき
// 累積和は{ 0, 1 } , { 1, 3 }, { 3, 6 } , { 5, 10 }になっている
// 2~4をとりたいとき、左: lower_bound取ってその1個前
// 右: upper_bound取ってその1個前
// e->secondでmapの対応する要素を取り出せる
// 累積和の取り出し方に慣れてないな…
int main() {
  int n; cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  map<int, ll> p;
  rep(i, n) {
    int val; cin >> val;
    if (i) p[x[i]] = p[x[i - 1]];
    p[x[i]] += val;
  }
  int q; cin >> q;
  while(q--) {
    int l, r; cin >> l >> r;
    auto s = p.lower_bound(l);
    auto e = p.upper_bound(r);
    ll ans = 0;
    if (e != p.begin()) {
      e--; ans = e->second;
    }
    if (s != p.begin()) {
      s--; ans -= s->second;
    }
    cout << ans << endl;
  }
}