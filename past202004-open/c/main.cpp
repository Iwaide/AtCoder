#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int M = 2 * N - 1;
  vector<vector<char>> T(N, vector<char>(M));
  rep(i, N) rep(j, M) cin >> T.at(i).at(j);

  vector<int> Y = { 1, 1, 1};
  vector<int> X = { -1, 0, 1 };
  for (int y = N - 1; y >= 0; y--) {
    for (int x = 0; x < M; x++) {
      if (T.at(y).at(x) != '#') continue;
      rep(k, 3) {
        int yi = y + Y.at(k);
        int xi = x + X.at(k);
        if (yi >= 0 && yi < N && xi >= 0 && xi < M) {
          if (T.at(yi).at(xi) == 'X') {
            T.at(y).at(x) = 'X';
          }
        }
      }
    }
  }
  rep(y, N) {
    rep(x, M) cout << T.at(y).at(x);
    cout << endl;
  }
}
