#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// void solve(int start, int goal, map<int, set<int>> &G, set<pair<int, int>> &roads) {
//   pair<int, int> s = make_pair(start, goal);
//   if (roads.count(s)) {
//     return;
//   }
//   roads.insert(s);
//   for(int next_goal: G[goal]) {
//     solve(start, next_goal, G, roads);
//   }
// }

// int main() {
//   int N, M;
//   cin >> N >> M;
//   map<int, set<int>> G;
//   set<pair<int, int>> roads;
//   rep(i, M) {
//     int Ai, Bi;
//     cin >> Ai >> Bi;
//     Ai--; Bi--;
//     G[Ai].insert(Bi);
//   }
//   rep(i, N) roads.insert(pair<int, int>{ i, i });

//   for(auto pair: G) {
//     for(int goal: pair.second) {
//       solve(pair.first, goal, G, roads);
//     }
//   }
//   cout << roads.size() << endl;
// }

int main() {
  int N, M;
  vector<int> E[2010];
  cin >> N >> M;
  rep(i, M) {
    int a, b; cin >> a >> b;
    a--; b--;
    E[a].push_back(b);
  }
  int ans = 0;
  rep(st, N) {
    queue<int> que;
    set<int> vis;
    // 次に探索しないといけないところ
    que.push(st);
    // すでに探索済みのところ
    vis.insert(st);

    while(!que.empty()) {
      int cu = que.front(); que.pop();
      for(int to : E[cu]) {
        if (!vis.count(to)) {
          que.push(to);
          vis.insert(to);
        }
      }
    }
    ans += vis.size();
  }
  cout << ans << endl;
}