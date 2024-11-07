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

// にN人の小学生が住んでおり、小学生iの家の位置はAiにある
// 小学校はN校あり、Bjにある
// 全員が別の学校に通うようにしたい
// 家からの距離の合計を最小化したい
int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  // ソートして取っていくしか無い気がするけど
  ll ans = 0;
  sort(all(A)); sort(all(B));
  rep(i, N) {
    ans += abs(A[i] - B[i]);
  }
  cout << ans << endl;
}

