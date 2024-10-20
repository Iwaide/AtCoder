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
// A 1, 3, 6
// B, 4, 5
// C, 2
// みたいな感じになってればいい気がする
int main() {
  string S; cin >> S;
  map<char, vector<int>> m;
  rep(i, S.size()) {
    m[S[i]].push_back(i);
  }
  ll ans = 0;
  // 各文字種に対して
  for(auto p : m) {
    // 1回しか出現しなかったら回文にならないのでスキップ
    if (p.second.size() == 1) {
      continue;
    }
    // 2重ループを回すと良くないか…
    for(int i = 0; i < p.second.size() - 1; i++) {
      for(int j = i + 1; j < p.second.size(); j++) {
        ans += p.second[j] - p.second[i] - 1;
      }
    }
  }
  cout << ans << endl;
}

