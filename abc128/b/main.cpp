#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> guides;
  rep(i, N) {
    string S;
    int P;
    cin >> S >> P;
    guides.push_back(make_tuple(S, -1 * P, i + 1));
  }
  sort(guides.begin(), guides.end());
  rep(i, N) {
    cout << get<2>(guides.at(i)) << endl;
  }
}
