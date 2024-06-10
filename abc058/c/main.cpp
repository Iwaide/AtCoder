#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<map<char, int>> w(n);
  rep(i, n) {
    string S;
    cin >> S;
    rep(j, S.size()) {
      w.at(i)[S.at(j)] += 1;
    }
  }
  for(char c = 'a'; c <= 'z'; c++) {
    int minimum = 100;
    rep(i, n) {
      minimum = min(minimum, w[i][c]);
    }
    rep(i, minimum) {
      cout << c;
    }
  }
  cout << endl;
}

