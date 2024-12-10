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

// 二次元平面に赤い点と青い点がN小ずつある
// 赤い点と青い点は赤い点のx座標が青い点のx座標より小さく、また赤い点のy座標も青い点のy座標より小さいとき仲良しペアになれる
// 最大で何個の仲良しペアを作れるか
// 1 <= N <= 100
int main() {
  int N; cin >> N;
  vector<pair<int, int>> A(N), B(N);
  rep(i, N) cin >> A[i].first >> A[i].second;
  rep(i, N) cin >> B[i].first >> B[i].second;
  // 青点をx座標でソート
  sort(all(B));
  // ペアになった赤点
  vector<bool> paired(N, false);
  int ans = 0;
  for(auto b : B) {
    tuple<int, int, int> red = { -1, -1, -1 };
    rep(i, N) {
      if (paired[i]) continue;
      auto a = A[i];
      if (a.first < b.first && a.second < b.second) {
        if (get<2>(red) < a.second) {
          red = { i, a.first, a.second };
        }
      }
    }
    if (get<0>(red) != -1) {
      ans++;
      paired[get<0>(red)] = true;
    }
  }
  cout << ans << endl;
}
