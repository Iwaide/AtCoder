#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   float A, B, W;
//   cin >> A >> B >> W;
//   W *= 1000;
//   int result_min = 1000000;
//   int result_max = -1;
//   rep2(i, 1, 1000001) {
//     float O = W / i;
//     if (O >= A && O <= B) {
//       result_min = min(i, result_min);
//       result_max = max(i, result_max);
//     }
//   }
//   if (result_max != -1) {
//     cout << result_min << " " << result_max << endl;
//   } else {
//     cout << "UNSATISFIABLE" << endl;
//   }
// }
int main() {
  int A, B, W;
  cin >> A >> B >> W;
  W *= 1000;
  int upper = W / A;
  int lower = (W + B - 1) / B;
  if (lower > upper) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << lower << " " << upper << endl;
  }
}