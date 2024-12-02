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

// 英小文字のみからなる長さNの文字列Sが与えられる
// 長さがKであるSの部分列のうち、辞書順で最小であるものを出力せよ
// 1 <= K <= N <= 100000
// 前から N - Kまで見ていって一番辞書順で小さいやつを取っていけば良さそうだけど
int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  string ans;
  int i = 0;
  rep(j, K) {
    char c = 'z';
    int index = i;
    for(int k = i; k <= N - (K - j); k++) {
      if (c > S[k]) {
        c = S[k];
        i = k + 1;
      }
    }
    ans += c;
  }
  cout << ans << endl;
}

