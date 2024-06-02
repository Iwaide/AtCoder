#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
  vector<int> Y = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
  vector<vector<char>> S(N, vector<char>(M));
  rep(i, N) rep(j, M) cin >> S.at(i).at(j);

  rep(y, N) {
    rep(x, M) {
      int result = 0;
      rep(k, X.size()) {
        int xi = x + X.at(k);
        int yi = y + Y.at(k);
        if (xi >= 0 && xi < M && yi >= 0 && yi < N) {
          if (S.at(yi).at(xi) == '#') {
            result++;
          }
        }
      }
      cout << result;
    }
    cout << endl;
  }
}

