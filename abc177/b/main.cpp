#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S, T;
  cin >> S >> T;
  int result = 1000;
  rep(i, S.size() - T.size() + 1) {
    int counter = 0;
    rep(j, T.size()) {
      if (S.at(i + j) != T.at(j)) counter++;
    }
    result = min(result, counter);
  }
  cout << result << endl;
}
