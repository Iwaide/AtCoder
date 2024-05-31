#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  vector<vector<bool>> Ab(3, vector<bool>(3, false));
  rep(i, 3) rep(j, 3) cin >> A.at(i).at(j);
  int N;
  cin >> N;
  rep(i, N) {
    int b;
    cin >> b;
    rep(j, 3) {
      rep(k, 3) {
        if (A.at(j).at(k) == b) {
          Ab.at(j).at(k) = true;
        }
      }
    }
  };
  // 横列
  rep(i, 3) {
    vector<bool> row = Ab.at(i);
    bool bingo = true;
    for(auto field: row) if (!field) bingo = false;
    if (bingo) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  // 縦列
  rep(i, 3) {
    bool bingo = false;
    if (Ab.at(0).at(i) && Ab.at(1).at(i) && Ab.at(2).at(i)) {
      bingo = true;
    }
    if (bingo) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  // 左斜め
  if (Ab.at(0).at(0) && Ab.at(1).at(1) && Ab.at(2).at(2)) {
    cout << "Yes" << endl;
    return 0;
  }
  // 右斜め
  if (Ab.at(0).at(2) && Ab.at(1).at(1) && Ab.at(2).at(0)) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}

