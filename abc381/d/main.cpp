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

# define N 200000
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int ans = 0;
  // siは開始位置(0, 1)
  rep(si, 2) {
    vector<int> cnt(n + 1);
    int r = si;
    // 2個ずつlをずらしていく
    for(int l = si; l + 1 < n; l += 2) {
      // rも2個ずつずれる
      while(r + 1 < n) {
        // すでに入ってる
        if (cnt[a[r]] != 0) break;
        // rとr+1が同じじゃないときはrを動かせない
        if (a[r] != a[r + 1]) break;
        cnt[a[r]]++;
        r += 2;
      }
      ans = max(ans, r - l);
      // lがrを追い越さないようにする
      if (l == r) r += 2;
      // 終わったらlを動かす
      chmax(r, l);
    }
  }
  cout << ans << endl;
}
