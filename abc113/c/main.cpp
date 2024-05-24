#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<tuple<int, int, long long>> points(N);
  rep(i, N) {
    int x, y;
    long long h;
    cin >> x >> y >> h;
    points.at(i) = make_tuple(x, y, h);
  }
  rep(Cx, 101) {
    rep(Cy, 101) {
      long long H = -1;
      bool can = true;
      for(auto point: points) {
        int xi, yi;
        long long hi;
        tie(xi, yi, hi) = point;
        long long Hi = hi + abs(xi - Cx) + abs(yi - Cy);
        if (H < 0) {
          H = Hi;
        } else {
          if (H == Hi) {
            continue;
          } else {
            can = false;
            break;
          }
        }
      }
      if (can) {
        cout << Cx << " " << Cy << " " << H << endl;
        return 0;
      }
    }
  }
}

