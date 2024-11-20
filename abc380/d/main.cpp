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

// 英大小文字からなる文字列S
// Sに以下の操作を10^100繰り返す
// sの大文字と小文字を入れ替えた文字列をTとする
// SとTを連結した文字列を新たなSとする
// Q個の質問に答えよ
// Sの先頭からKi文字目を求めよ
// 完全2分木の考え方

char flip(char c) {
  if ('a' <= c && c <= 'z') {
    return (c - 'a') + 'A';
  } else {
    return (c - 'A') + 'a';
  }
}
int main() {
  string S;
  cin >> S;
  int Q; cin >> Q;
  vector<char> res;
  rep(i, Q) {
    if (i) cout << " ";
    ll K; cin >> K; K--;
    ll block = K / S.size();
    ll pt = K % S.size();
    if (__builtin_popcountll((unsigned long long)block) % 2) {
      cout << flip(S[pt]);
    } else {
      cout << S[pt];
    }
  }
  cout << endl;
  print_vector(res);
}

