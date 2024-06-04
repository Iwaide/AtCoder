#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   int A, B, C, X, Y;
//   cin >> A >> B >> C >> X >> Y;
//   long long result = 1000000000000; 
//   rep(c, 100000 * 2 + 1) {
//     int rest_A = max(X - c / 2, 0);
//     int rest_B = max(Y - c / 2, 0);
//     long long tmp = rest_A * A + rest_B * B + c * C;
//     result = min(tmp, result);
//   }
//   cout << result << endl;
// }

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int max_xy = max(X, Y);
  int min_xy = min(X, Y);
  long long ans1 = A * X + B * Y;
  // できるだけABを買う
  long long ans2 = max_xy * 2 * C;
  // ABが最小になるように買う
  long long ans3 = min_xy * 2 * C + max(X - min_xy, 0) * A + max(Y - min_xy, 0) * B;
  cout << min(ans1, min(ans2, ans3)) << endl;
}