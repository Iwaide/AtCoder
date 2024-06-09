#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<vector<char>> f(int n) {
  if (n == 0) return vector<vector<char>> {{ '#' }};
  vector<vector<char>> sub = f(n - 1);
  int len = sub.size();
  vector<vector<char>> rect(len * 3, vector<char>(len * 3, '.'));
  rep(I, 3) {
    rep(J, 3) {
      if (!(I == 1 && J == 1)) {
        rep(i, len) {
          rep(j, len) {
            rect[I * len + i][J * len + j] = sub.at(i).at(j);
          }
        }
      }
    }
  }
  return rect;
}

int main() {
  int N;
  cin >> N;
  vector<vector<char>> ans = f(N);
  for(vector<char> row: ans) {
    for(char field: row) {
      cout << field;
    }
    cout << endl;
  }
}

