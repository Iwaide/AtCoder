#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

map<int, vector<int>> G;

void insert_graph(int x, int y) {
  if (G.count(x)) {
    G[x].push_back(y);
  } else {
    G.insert(make_pair(x, vector<int> { y }));
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  rep(i, M) {
    int ai, bi;
    cin >> ai >> bi;
    ai--;bi--;
    insert_graph(ai, bi);
    insert_graph(bi, ai);
  }
  rep(i, N) {
    if (G.count(i)) {
      vector<int> roads = G.at(i);
      cout << roads.size() << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
