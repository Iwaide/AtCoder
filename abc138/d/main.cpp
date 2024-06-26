#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, Q;
  cin >> N >> Q;
  map<int, set<int>> tree;
  rep(i, N - 1) {
    int ai, bi;
    cin >> ai >> bi;
    tree[ai].insert(bi);
    tree[bi].insert(ai);
  }
  vector<long long> ans(N + 1, 0);
  rep(i, Q) {
    int pi, xi;
    cin >> pi >> xi;
    ans[pi] += xi;
  }
  queue<int> que;
  que.push(1);
  set<int> vis = { 1 };
  while(que.size() > 0) {
    int current = que.front(); que.pop();
    int current_number = ans[current];

    for(int node : tree[current]) {
      if (vis.count(node)) continue;

      ans[node] += current_number;
      vis.insert(node);
      que.push(node);
    }
  }

  rep2(i, 1, N + 1) {
    cout << ans[i];
    if (i == N) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

