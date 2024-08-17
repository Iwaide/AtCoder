#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()

// きたなすぎ
int main() {
  string X; cin >> X;
  string a, b;
  bool isSyosu = false;
  for(int i = 0; i < X.size(); i++) {
    if (X[i] == '.') {
      isSyosu = true;
      continue;
    }
    if (isSyosu) {
      b += X[i];
    } else {
      a += X[i];
    }
  }
  string newB;
  bool renzoku = true;
  for(int i = b.size() - 1; i >= 0; i--) {
    if (renzoku && b[i] == '0') {
      continue;
    } else {
      newB += b[i];
      renzoku = false;
    }
  }
  reverse(all(newB));
  cout << a;
  if (newB.size() > 0) {
    cout << "." << newB;
  }
  cout << endl;
}

