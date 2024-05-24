#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));

  vector<bool> row(H);
  vector<bool> column(W);

  rep(i, H) {
    rep(j, W) {
      char c;
      cin >> c;
      grid.at(i).at(j) = c;
      if (c == '#') {
        row.at(i) = true;
        column.at(j) = true;
      }
    }
  }
  rep(i, H) {
    if (!row.at(i)) continue;
    rep(j, W) {
      if (column.at(j)) cout << grid.at(i).at(j);
    }
    cout << endl;
  }
}

