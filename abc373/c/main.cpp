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

// 長さNの整数列A, B |Ai, Bi| <= 10^9
// 1以上N以下の整数i,jを選んでAi, Bjの値を最大化しろ
int main() {
  int N; cin >> N;
  ll Amax = LONG_LONG_MIN, Bmax = LONG_LONG_MIN;
  rep(i, N) {
    ll Ai;
    cin >> Ai;
    chmax(Amax, Ai);
  }
  rep(i, N) {
    ll Bi;
    cin >> Bi;
    chmax(Bmax, Bi);
  }
  cout << (Amax + Bmax) << endl;
}

