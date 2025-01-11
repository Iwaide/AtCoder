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

// N匹の蛇
// 太さTi, 長さLi
// 重さは太さと長さの積
// すべての蛇の長さがk伸びたときの最も重い蛇の重さを求めよ
int main() {
  int N, D;
  cin >> N >> D;
  vector<pair<int, int>> snakes(N);
  rep(i, N) {
    cin >> snakes[i].first >> snakes[i].second;
  }

  for(int k = 1; k <= D; k++) {
    int ans = 0;
    rep(i, N) {
      chmax(ans, snakes[i].first * (snakes[i].second + k));
    }
    cout << ans << endl;
  }
}

