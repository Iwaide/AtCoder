#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;

  // ここにプログラムを追記a
  rep(i, N) {
    string color;
    cin >> color;
    if (color == "Y") {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
}
