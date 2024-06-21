#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

map<int, set<int>> G;

void insert_graph(int x, int y) {
  if (G.count(x)) {
    G[x].insert(y);
  } else {
    G.insert(make_pair(x, set<int> { y }));
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> H(N);
  rep(i, N) cin >> H.at(i);

  rep(i, M) {
    int Ai, Bi;
    cin >> Ai >> Bi;
    Ai--; Bi--;
    insert_graph(Ai, Bi);
    insert_graph(Bi, Ai);
  }

  int result = 0;
  rep(i, N) {
    if (G.count(i)) {
      set<int> peaks = G.at(i);
      long long Hi = H.at(i);
      bool good = true;
      for(long long j : peaks) {
        long long Hj = H.at(j);
        if (Hi <= Hj) {
          good = false;
          break;
        } 
      }
      if (!good) continue;
      result++;
    } else {
      result++;
    }
  }

  cout << result << endl;
}

