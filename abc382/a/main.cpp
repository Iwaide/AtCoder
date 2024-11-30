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

// N個の箱が横一列に並んでおり、そのうちのいくつかの箱にはクッキーが入っている
// @のときクッキーが1枚.のとき空き箱
// N個のはこの内、D日間が経過下後に空き箱であるものはいくつあるか求めよ
int main() {
  int N, D; cin >> N >> D;
  string S; cin >> S;
  int cookie_cnt = 0;
  rep(i, S.size()) {
    if (S[i] == '@') cookie_cnt++;
  }
  cout << max(0, N - (cookie_cnt - D)) << endl;
}
