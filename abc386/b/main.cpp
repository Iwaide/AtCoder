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

// 00, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9のボタンがある電卓
// 文字列Sを表示させるためにボタンを押す回数の最小値を求めよ
int main() {
  string S;
  cin >> S;
  int ans = 0;
  for(int i = 0; i < S.size(); i++) {
    ans++;
    if (S[i] != '0') continue;
    if (i < (S.size() - 1) && S[i+1] == '0') {
      i++;
    }
  }
  cout << ans << endl;
}

