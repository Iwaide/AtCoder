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

// 2次元平面上N点(X1, Y1)...(XN, YN)に家が建っている
// 最初点(Sx, Sy)にサンタがいる
// (Di, Ci)にしたがって以下の行動をM回行う
// DiがUなら(x, y)から(x, y + Ci)に直線で移動する
// 行動を終えた後にサンタクロースがいる点と行動により通過、到達した家の数を求めよ
// x, yでそれぞれmapで持っておいて、移動前upper_boundと移動後lower_boundで取っていけば良さそうだけど
int main() {
  ll N, M, Sx, Sy;
  cin >> N >> M >> Sx >> Sy;
  map<ll, set<ll>> XN, YN;
  rep(i, N) {
    ll Xi, Yi;
    cin >> Xi >> Yi;
    XN[Xi].insert(Yi);
    YN[Yi].insert(Xi);
  }
  int ans = 0;
  rep(i, M) {
    char Di; ll Ci;
    cin >> Di >> Ci;
    if (Di == 'U') {
      // yの値を指すindex
      auto s = XN[Sx].lower_bound(Sy);
      auto e = s;
      ll to = Sy + Ci;
      while(e != XN[Sx].end() && *e <= to) {
        ans++;
        YN[*e].erase(Sx);
        e++;
      }
      XN[Sx].erase(s, e);
      Sy = to;
    } else if (Di == 'D') {
      // yの値を指すindex
      ll to = Sy - Ci;
      auto s = XN[Sx].lower_bound(to);
      auto e = s;
      while(e != XN[Sx].end() && *e <= Sy) {
        ans++;
        YN[*e].erase(Sx);
        e++;
      }
      XN[Sx].erase(s, e);
      Sy = to;
    } else if (Di == 'R') {
      // xの値を指すindex
      auto s = YN[Sy].lower_bound(Sx);
      auto e = s;
      ll to = Sx + Ci;
      while(e != YN[Sy].end() && *e <= to) {
        ans++;
        XN[*e].erase(Sy);
        e++;
      }
      YN[Sy].erase(s, e);
      Sx = to;
    } else if (Di == 'L') {
      // xの値を指すindex
      ll to = Sx - Ci;
      auto s = YN[Sy].lower_bound(to);
      auto e = s;
      while(e != YN[Sy].end() && *e <= Sx) {
        ans++;
        XN[*e].erase(Sy);
        e++;
      }
      YN[Sy].erase(s, e);
      Sx = to;
    }
  }
  cout << Sx << ' ' << Sy << ' ' << ans << endl;
}
