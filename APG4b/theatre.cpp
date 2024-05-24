#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int result = 0;
  // ここにプログラムを追記a
  rep(i, N) {
    int A, B;
    cin >> A >> B;
    result += B + 1 - A;
  }
  cout << result << endl;
}
