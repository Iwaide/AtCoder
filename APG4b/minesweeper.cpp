#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> vec(H);
  rep(i, H) {
    cin >> vec.at(i);
  }
  rep(m, H) {
    rep(n, W) {
      if (vec.at(m).at(n) == '#') {
        cout << '#';
        continue;
      } 
      int count = 0;
      rep2(i, -1, 2) {
        rep2(k, -1, 2) {
          int t = m + i;
          int u = n + k;
          if (t >= 0 && t < H && u >= 0 && u < W) {
            if (vec.at(t).at(u) == '#') {
              count++;
            }
          }
        }
      }
      cout << count;
    }
    cout << endl;
  }
}
