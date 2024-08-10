#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// 2次元平面上の
int main() {
  int N, D;
  cin >> N >> D;
  vector<pair<int, int>> points;
  rep(i, N) {
    int x, y; cin >> x >> y;
    points.push_back(make_pair(x, y));
  }
  vector<set<pair<int, int>>> ans;
  rep(i, N) {
    
  }
}

