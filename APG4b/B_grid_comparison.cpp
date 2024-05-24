#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   int H, W;
//   cin >> H >> W;
//   vector<vector<char>> grid(H, vector<char>(W));
//   rep(i, H) {
//     rep(j, W) {
//       cin >> grid.at(i).at(j);
//     }
//   }
//   rep(i, H) {
//     bool is_blank = true;
//     rep(j, W) {
//       if (grid.at(i).at(j) == '#') {
//         is_blank = false;
//         break;
//       }
//     }
//     if (is_blank) {
//       grid.erase(grid.begin() + i);
//       H--;
//       i--;
//     }
//   }
//   rep(j, W) {
//     bool is_blank = true;
//     rep(i, H) {
//       if (grid.at(i).at(j) == '#') {
//         is_blank = false;
//         break;
//       }
//     }
//     if (is_blank) {
//       rep(i, H) {
//         grid.at(i).erase(grid.at(i).begin() + j);
//       }
//       W--;
//       j--;
//     }
//   }
//   rep(i, H) {
//     rep(j, W) {
//       cout << grid.at(i).at(j);
//     }
//     cout << endl;
//   }
// }

int main() {
    int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  vector<bool> row(H, false);
  vector<bool> column(W, false);
  rep(i, H) rep(j, W) cin >> grid.at(i).at(j);
  rep(i, H) {
    rep(j, W) {
      if (grid.at(i).at(j) == '#') {
        row.at(i) = true;
        column.at(j) = true;
      }
    }
  }
  rep(i, H) {
    if (row.at(i)) {
      rep(j, W) {
        if (column.at(j)) {
          cout << grid.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}