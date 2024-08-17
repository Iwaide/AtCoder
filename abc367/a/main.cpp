#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()

// A時に起きているか
// B時に寝る
// C時に起きる
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (B > C) {
    if (A > C && B > A) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    if (A > C || B > A) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}

