#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

pair<int, int> current;
int H, W, Si, Sj;

void move(vector<vector<char>> &G, int deltaX, int deltaY) {
  int movedX = current.first + deltaX;
  int movedY = current.second + deltaY;
  if (movedX < 0 || movedX >= H || movedY < 0 || movedY >= W) {
    return;
  }
  if (G[movedX][movedY] == '#') {
    return;
  }
  current.first = movedX; current.second = movedY;
  return;
}

int main() {
  cin >> H >> W >> Si >> Sj;
  Si--; Sj--;
  current = make_pair(Si, Sj);
  vector<vector<char>> G(H, vector<char>(W));

  rep(i, H) {
    rep(j, W) {
      cin >> G[i][j];
    }
  }

  string X;
  cin >> X;
  rep(i, X.size()) {
    char c = X[i];
    if (c == 'L') {
      move(G, 0, -1);
    } else if (c == 'R') {
      move(G, 0, 1);
    } else if (c == 'U') {
      move(G, -1, 0);
    } else if (c == 'D') {
      move(G, 1, 0);
    } 
  }

  cout << ++current.first << " " << ++current.second << endl;
}

