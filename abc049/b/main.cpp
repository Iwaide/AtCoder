#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   int H, W;
//   cin >> H >> W;
//   vector<vector<char>> C(H + 1, vector<char>(W + 1));
//   rep2(i, 1, H + 1) rep2(j, 1, W + 1) cin >> C.at(i).at(j);
//   rep2(i, 1, H * 2 + 1) {
//     rep2(j, 1, W + 1) {
//       cout << C.at((i + 1) / 2).at(j);
//     }
//     cout << endl;
//   }
// }

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> C(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> C.at(i).at(j);
  rep(i, H) {
    rep(j, W) cout << C.at(i).at(j);
    cout << endl;
    rep(j, W) cout << C.at(i).at(j);
    cout << endl;
  }
}
