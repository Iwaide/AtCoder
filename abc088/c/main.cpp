#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   vector<vector<int>> c(3, vector<int>(3));
//   rep(i, 3) rep(j, 3) cin >> c.at(i).at(j);
//   rep(a1, 101) {
//     int b1 = c.at(0).at(0) - a1;
//     rep(a2, 101) {
//       int b2 = c.at(1).at(1) - a2;
//       rep(a3, 101) {
//         int b3 = c.at(2).at(2) - a3;
//         if (
//           a1 + b2 == c.at(0).at(1) &&
//           a1 + b3 == c.at(0).at(2) &&
//           a2 + b1 == c.at(1).at(0) &&
//           a2 + b3 == c.at(1).at(2) &&
//           a3 + b1 == c.at(2).at(0) &&
//           a3 + b2 == c.at(2).at(1)
//         ) {
//           cout << "Yes" << endl;
//           return 0;
//         }
//       }
//     }
//   }
//   cout << "No" << endl;
// }

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> c.at(i).at(j);
  int a1 = 0;
  int b1 = c.at(0).at(0) - a1;
  int b2 = c.at(0).at(1) - a1;
  int b3 = c.at(0).at(2) - a1;
  int a2 = c.at(1).at(1) - b2;
  int a3 = c.at(2).at(2) - b3;
  if (
    a2 + b1 == c.at(1).at(0) &&
    a2 + b3 == c.at(1).at(2) &&
    a3 + b1 == c.at(2).at(0) &&
    a3 + b2 == c.at(2).at(1)
  ) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
