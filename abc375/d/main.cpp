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

// 英大文字からなる文字列Sが与えられる
// 整数の組(i, j, k)であって以下の条件をともに満たすものの個数を求めよ
// 1 <= i < j < k <= |S|
// Si, Sj, Skをこの順に結合して得られる長さ3の文字列が回文となる
// Sは長さ1以上2*10^5以下
// 回文になる条件はSiとSkが同じ文字であること
// 真ん中を固定してそこからiとkを逆算して求める
// i j kで分割してjを左からずらしていく
int main() {
  string s; cin >> s;
  // lcntはiの組, rcntはjの組
  map<char, int> lcnt, rcnt;
  // rcntを作っておく
  rep(i, s.size()) rcnt[s[i]]++;

  ll ans = 0;
  rep(i, s.size()) {
    // jをiの位置に持ってくる
    // rcntから除去
    rcnt[s[i]]--;

    // 各文字種に対して
    for(char c = 'A'; c <= 'Z'; c++) {
      ans += (ll) lcnt[c] * rcnt[c];
    }

    // 計算終わったらlcntに追加しておく
    lcnt[s[i]]++;
  }

  cout << ans << endl;
}
