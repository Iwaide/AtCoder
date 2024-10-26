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

// N * Nのマス目
// コマをいくつ置けるか
// Nは10^9だけど、Mは2*10^5だからMベースで考えていくと良さそう？
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1 };
int main() {
  ll N, M; cin >> N >> M;
  set<pair<int, int>> s;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    s.insert({ a, b });
    rep(j, 8) {
      int x = dx[j] + a, y = dy[j] + b;
      if (x >= 0 && x < N && y >= 0 && y < N) {
        s.insert({ x, y });
      }
    }
  }
  ll ans = N * N;
  cout << ans - s.size() << endl;
}
