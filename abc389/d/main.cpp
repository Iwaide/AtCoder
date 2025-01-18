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

// 二次元平面上に1*1の正方形が無限に敷き詰められている
// 正方形をの中心を中心として、半径Rの円を描いたときに円に完全に内包される正方形は何個あるか？
// (i + 0.5, j + 0.5), ...すべてが原点との距離がR以下となるものの個数
int main() {
  double R; cin >> R;
  ll ans = 0, t;
  // 正の整数組i, jが
  rep(i, R) {
    // jを2分探索する
    ll ok = 0, ng = R;
    while(ng - ok > 1) {
      ll mid = (ok + ng) / 2;
      double dist = ((double)i + 0.5) * ((double)i + 0.5) + ((double) mid + 0.5) * ((double) mid + 0.5);
      if (dist < R * R) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    int tmp = ok + 1;
    if (i == 0) t = tmp; 
    if (ok >= 0) {
      ans += tmp;
    }
  }
  cout << ans * 4 - t * 4 + 1 << endl;
}

