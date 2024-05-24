#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  vector<vector<char>> result(N, vector<char>(N, '-'));
  // for (int i = 0; i < M; i++) {
  //   cin >> A.at(i) >> B.at(i);
  // }
  // rep(i, M) {
  //   int winner = A.at(i);
  //   int looser = B.at(i);
  //   result.at(winner - 1).at(looser - 1) = 'o';
  //   result.at(looser - 1).at(winner - 1) = 'x';
  // }

  rep(i, M) {
    int winner, looser;
    cin >> winner >> looser;
    result.at(winner - 1).at(looser - 1) = 'o';
    result.at(looser - 1).at(winner - 1) = 'x';
  }
  rep(i, N) {
    rep(j, N) {
      cout << result.at(i).at(j);
      if (j != N -1) cout << ' ';
    }
    cout << endl;
  }
}
