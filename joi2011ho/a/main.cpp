#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int M, N, K;
  cin >> M >> N >> K;
  vector<vector<int>> J(M, vector<int>(N + 1, 0));
  vector<vector<int>> O(M, vector<int>(N + 1, 0));
  vector<vector<int>> I(M, vector<int>(N + 1, 0));
  rep(i, M) {
    rep(j, N) {
      char c; cin >> c;
      J.at(i).at(j + 1) = J.at(i).at(j) + (c == 'J' ? 1 : 0);
      I.at(i).at(j + 1) = I.at(i).at(j) + (c == 'I' ? 1 : 0);
      O.at(i).at(j + 1) = O.at(i).at(j) + (c == 'O' ? 1 : 0);
    }
  }
  rep(i, K) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; c--;
    int Ic = 0, Oc = 0, Jc = 0; 
    for(int y = a; y <= c; y++) {
      Ic += I.at(y).at(d) - I.at(y).at(b - 1);
      Oc += O.at(y).at(d) - O.at(y).at(b - 1);
      Jc += J.at(y).at(d) - J.at(y).at(b - 1);
    }
    cout << Jc << " " << Oc << " " << Ic << endl;
  }
}

