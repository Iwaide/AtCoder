#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> v(N, vector<bool>(N, false));
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    v[x][y] = true;
    v[y][x] = true;
  }
  int result = 0;
  rep(i, (1 << N)) {
    bitset<12> b(i);
    int disable = false;
    rep(j, N) {
      if (!b.test(j)) continue;
      rep2(k, j + 1, N) {
        if (!b.test(k)) continue;
        if (!v.at(j).at(k)) {
          disable = true;
          break;
        }
      }
      if (disable) break;
    }
    if (!disable) result = max(result, (int) b.count());
  }
  cout << result << endl;
}

