#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<map<int, bool>>Mmap(N);
  rep(i, N) {
    string S;
    cin >> S;
    map<int, bool> pop;
    rep(j, M) pop[j] = S.at(j) == 'o';
    Mmap.at(i) = pop;
  }
  int result = 10;
  rep(i, (1 << N)) {
    bitset<10> b(i);
    map<int, bool> all;
    rep(j, N) {
      if (!b.test(j)) continue;
      map<int, bool> uriba = Mmap.at(j);
      for(auto pair: uriba) {
        if (all.count(pair.first)) {
          all[pair.first] = all[pair.first] || pair.second;
        } else {
          all[pair.first] = pair.second;
        }
      }
    }
    if (all.size() != M) continue;

    bool can = true;
    for(auto pair: all) {
      if (!pair.second) {
        can = false;
        break;
      }
    }
    if (can) {
      result = min(result, (int)b.count());
    }
  }
  cout << result << endl;
}
