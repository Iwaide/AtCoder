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
  int cnt = 0;
  rep(i, N) {
    int tmp = 0;
    for(int other: G[i]) {
      if (other < i) tmp++;
    }
    if (tmp == 1) cnt++;
  }
  cout << cnt << endl;
}

