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

// 価値viを持つN個の具材
// 2個の具材を鍋に入れると1この具材が生成される
// (x + y) / 2の価値になる
// N - 値として考えられる最大値を求めよ
// 価値の大きい食材を後回しにしていけばよさそう
int main() {
  int N; cin >> N;
  vector<float> foods(N);
  rep(i, N) cin >> foods[i];
  sort(all(foods));
  float ans = foods[0];
  rep2(i, 1, N) {
    ans = (ans + foods[i]) / 2.0f;
  }
  cout << ans << endl;
}

