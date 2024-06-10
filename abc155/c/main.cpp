#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  map<string, int> Smap;
  int maximum = 0;
  rep(i, N) {
    string S;
    cin >> S;
    if (Smap.count(S)) {
      Smap.at(S) += 1;
    } else {
      Smap.insert(make_pair(S, 1));
    }
    maximum = max(maximum, Smap.at(S));
  }
  vector<string> result;
  for(auto pair: Smap) {
    if (pair.second == maximum) {
      // map内はsortされてるのでそのまま出力でいい
      cout << pair.first << endl;
    }
  }
}

