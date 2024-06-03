#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> sc(M);
  rep(i, M) {
    int s, c;
    cin >> s >> c;
    sc.at(i) = make_pair(s, c);
  }
  rep(i, 1000) {
    string s = to_string(i);
    if (s.size() != N) continue;

    bool can = true;
    for(auto sci: sc) {
      if (s.substr(sci.first - 1, 1) != to_string(sci.second)) {
        can = false;
        break;
      }
    }
    if (can) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}

