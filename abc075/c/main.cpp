#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int N, M;
  cin >> N >> M;
  map<int, set<int>> G;
  vector<pair<int, int>> sides(M);
  rep(i, M) {
    int ai, bi;
    cin >> ai >> bi; ai--; bi--;
    G[ai].insert(bi);
    G[bi].insert(ai);
    sides.at(i) = make_pair(ai, bi);
  }
  int result = 0;
  rep(i, M) {
    auto side = sides.at(i);
    G[side.first].erase(side.second);
    G[side.second].erase(side.first);

    set<int> vis = { 0 };
    queue<int> que; que.push(0);

    while(que.size() > 0) {
      int current = que.front(); que.pop();
      for (auto p : G[current]) {
        if (vis.count(p)) continue;
        vis.insert(p);
        que.push(p);
      }
    }
    if (vis.size() != N) result++;

    G[side.first].insert(side.second);
    G[side.second].insert(side.first);
  }

  cout << result << endl;
}

