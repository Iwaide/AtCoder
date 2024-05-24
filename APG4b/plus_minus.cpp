#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string S;
  cin >> S;

  int result = 1;
  // ここにプログラムを追記
  rep(i, S.size()) {
    if(i % 2 != 0) {
      if (S.at(i) == '+') {
        result++;
      } else {
        result--;
      }
    }
  }
  cout << result << endl;
}
