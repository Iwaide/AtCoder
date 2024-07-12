#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
  int Y, X, K;
  cin >> Y >> X >> K;
  vector<vector<int>> J(Y + 1, vector<int>(X + 1, 0));
  vector<vector<int>> I(Y + 1, vector<int>(X + 1, 0));
  vector<vector<int>> O(Y + 1, vector<int>(X + 1, 0));
  vector<vector<char>>F(Y, vector<char>(X));

  rep(y, Y) rep(x, X) cin >> F[y][x];

  rep(y, Y) {
    rep(x, X) {
      J[y + 1][x + 1] = J[y + 1][x] + J[y][x + 1] - J[y][x] + (F[y][x] == 'J' ? 1 : 0);
      I[y + 1][x + 1] = I[y + 1][x] + I[y][x + 1] - I[y][x] + (F[y][x] == 'I' ? 1 : 0);
      O[y + 1][x + 1] = O[y + 1][x] + O[y][x + 1] - O[y][x] + (F[y][x] == 'O' ? 1 : 0);
    }
  }

  rep(i, K) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;
    int Jc = J[y2 + 1][x2 + 1] - J[y1][x2 + 1] - J[y2 + 1][x1] + J[y1][x1];
    int Ic = I[y2 + 1][x2 + 1] - I[y1][x2 + 1] - I[y2 + 1][x1] + I[y1][x1];
    int Oc = O[y2 + 1][x2 + 1] - O[y1][x2 + 1] - O[y2 + 1][x1] + O[y1][x1];
    cout << Jc << " " << Oc << " " << Ic << endl;
  }
}