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
int main() {
  int N; cin >> N;
  string S; cin >> S;
  // 0: 1をカウントする 1: 2をカウントする
  int mode = 0;
  map<char, int> cnt;
  int ans = 0;
  for(int i = 0; i < S.size(); i++) {
    if (S[i] == '/') chmax(ans, 1);

    if (mode == 0) {
      if (S[i] == '1') {
        cnt['1'] += 1;
      } else if (S[i] == '/') {
        mode = 1;
      } else {
        cnt['1'] = 0; cnt['2'] = 0;
      }
    } else if (mode == 1) {
      if (S[i] == '2') {
        cnt['2'] += 1;
        chmax(ans, min(cnt['2'], cnt['1']) * 2 + 1);
      } else {
        chmax(ans, min(cnt['2'], cnt['1']) * 2 + 1);
        mode = 0;
        cnt['1'] = 0; cnt['2'] = 0;
        if (S[i] == '1') {
          cnt['1'] += 1;
        }
      }
    }
  }
  cout << ans << endl;
}

