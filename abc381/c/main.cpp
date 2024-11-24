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

// Tは11/22文字列
// Sの中で11/22文字列となるような部分文字列の長さの最大値を求めよ
// /を決め売ったときの左右の1, 2の広がりを調べる
int main() {
  int N; cin >> N;
  string S; cin >> S;
  int ans = 0;
  rep(i, N) {
    if (S[i] != '/') continue;
    int d = 0;
    while(true) {
      int l = i - (d + 1), r = i + (d + 1);
      if (l < 0 && r > N) break;
      if (S[l] != '1' || S[r] != '2') break;
      d++;
    }
    chmax(ans, d * 2 + 1);
  }
  cout << ans << endl;
}

