#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> pic(H);
  rep(i, H)
    cin >> pic.at(i);
  string top_bottom_frame;
  rep(i, W + 2)
    top_bottom_frame += '#';
  cout << top_bottom_frame;
  cout << endl;
  rep(i, H) {
    cout << '#' << pic.at(i) << '#' << endl;
  }
  cout << top_bottom_frame;
  cout << endl;
}


int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> matrix(H + 2, vector<char>(W + 2, '#'));
  vector<vector<char>> pic(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> pic.at(i).at(j);
    }
  }
  rep(i, H) {
    rep(j, W) {
      matrix.at(i + 1).at(j + 1) = pic.at(i).at(j);
    }
  }
  rep(i, H + 2) {
    rep(j, W + 2) {
      cout << matrix.at(i).at(j);
    }
    cout << endl;
  }
}