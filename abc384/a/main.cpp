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

// 長さNの英小文字列S、英語小文字c1, c2が与えられる
// Sの文字の内c1であるもの以外をすべてc2に置き換えた文字を求めよ
int main() {
  int N;
  char c1, c2;
  string S;
  cin >> N >> c1 >> c2 >> S;
  rep(i, N) {
    if (S[i] != c1) {
      cout << c2;
    } else {
      cout << S[i];
    }
  }
  cout << endl;
}

