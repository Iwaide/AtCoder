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
    cout << vec[i] << endl;
  }
}

// すぬけ君は空の数列aを持っている
// aに対してN回の操作を行う
// i回目の操作では1 <= j <= iを満たす整数jを選びaの先頭からj番目にjを挿入するとができる
// 長さNの数列bが与えられる、N回の操作後にaがbと一致することがあるかどうか判定し
// 可能ならばそれを達成する操作手順の一例を示せ
// 操作を逆順に考える、という発送がなかった
int main() {
  int N; cin >> N;
  vector<int> b(N);
  rep(i, N) cin >> b[i];
  vector<int> ans;
  // k番目のボールのうち最も右にあるものを削除する
  while(b.size() > 0) {
    int k = 0;
    for(int i = 1; i <= b.size(); i++) {
      if (b[i - 1] == i) {
        chmax(k, i);
      }
    }
    if (k == 0) {
      cout << -1 << endl;
      return 0;
    } else {
      ans.push_back(k);
      b.erase(b.begin() + k - 1);
    }
  }
  reverse(all(ans));
  print_vector(ans);
}
