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

// N個のオセロの石が一列に並んでいる
// B=黒 W=白
// i番目が黒、i+1が白のとき共に裏返す
// これを何回行えるか求めよ
// 最終的にはWWWW,,,BBBBみたいな感じになる
// Wの出たindexから数を引く感じ？
int main() {
  string S; cin >> S;
  ll w_cnt = 0, ans = 0;
  rep(i, S.size()) {
    if (S[i] == 'W') {
      ans += i - w_cnt;
      w_cnt++;
    }
  }
  cout << ans << endl;
}

