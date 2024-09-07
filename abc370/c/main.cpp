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

// 英小文字からなる文字列S, T |S| == |T|
// Xを空の配列とし、以下の操作をS, Tが等しくなるまで繰り返す
// Sの文字を1文字書き換え、Xの末尾にSを追加する
// Xのうち要素数最小のものを求める
// S = abde, T = bcbc
// Sをacdeにし、 X += acde
// Sをacbcにし、 X += acbc
// Sをbcbcにし、 X += bcbc
int main() {
  string S, T; cin >> S >> T;
  string D = S;
  vector<string> X;
  int cnt = 0;

  // 書き換える回数
  rep(i, S.size()) {
    vector<string> tmpX;
    string d = D;
    // どこを書き換えるか
    rep(j, S.size()) {
      if (d[j] != T[j]) {
        d[j] = T[j];
        tmpX.push_back(d);
        d[j] = D[j];
      }
    }
    if(tmpX.size() > 0) {
      sort(all(tmpX));
      string x = tmpX[0];
      X.push_back(x);
      cnt++;
      D = x;
    }
  }
  cout << cnt << endl;
  for(string x : X) {
    cout << x << endl;
  }
}

