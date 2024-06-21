#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  map<int, set<int>> G;
  rep(i, M) {
    int ai, bi;
    cin >> ai >> bi;
    ai--; bi--;
    G[ai].insert(bi);
    G[bi].insert(ai);
  }
  if (G.count(0) && G.count(N - 1)) {
    set<int> intersection;
    set_intersection(G[0].begin(), G[0].end(), G[N-1].begin(), G[N-1].end(), inserter(intersection, intersection.begin()));
    if (!intersection.empty()) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}

