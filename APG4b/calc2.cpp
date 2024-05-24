#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  rep(i, N) {
    string op;
    cin >> op;
    int B;
    cin >> B;
    if (op == "+") {
      A += B;
    } else if (op == "-") {
      A -= B;
    } else if (op == "*") {
      A *= B;
    } else if (op == "/") {
      if (B == 0) {
        cout << "error" << endl;
        break;
      }
      A /= B;
    }
    cout << i + 1 << ":" << A << endl;
  }
}
