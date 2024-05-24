#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int x = N;
  int fx = 0;
  while(x) {
    fx += x % 10;
    x /= 10;
  }
  if (N % fx == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

// int main() {
//   int N;
//   cin >> N;
//   int max = 9;
//   int sum = 0;
//   int A = 1;
//   int B = 1;
// NOTE: これは12とかの小さい数字でもmax回ループしちゃうから効率が良くないね
// while使い慣れてないなぁ
//   rep(i, max) {
//     B *= 10;
//     sum += N % B / A;
//     A *= 10;
//   }
//   if (N % sum == 0) {
//     cout << "Yes" << endl;
//   } else {
//     cout << "No" << endl;
//   }
// }
