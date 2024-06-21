#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  map<int, vector<int>> G;
  rep2(i, 1, N) {
    int Ai;
    cin >> Ai;
    Ai--;
    if (G.count(Ai)) {
      G.at(Ai).push_back(i - 1);
    } else {
      G.insert(make_pair(Ai, vector<int> { i - 1 }));
    }
  }
  rep(i, N) {
    if (G.count(i)) {
      cout << G.at(i).size() << endl;
    } else {
      cout << 0 << endl;
    }
  }
}

