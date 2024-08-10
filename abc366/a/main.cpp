#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  int half = (N + 1) / 2;
  if (T >= half || A >= half) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

