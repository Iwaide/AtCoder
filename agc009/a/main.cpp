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

// 正数列A1..ANとN個のボタンがある
// i個目のボタンを押すと、Aの1からi項目までの値が1ずつ増加する
// 正数列B1...BNの倍数になるようにしろ
// 右から考えていけばいいんじゃね
int main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  ll ans = 0;
  for(int i = N - 1; i >= 0; i--) {
    int mod = (A[i] + ans) % B[i];
    if (mod == 0) continue;

    ans += B[i] - mod;
  }
  cout << ans << endl;
}

