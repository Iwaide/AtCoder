#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> p(N, vector<bool>(N, false));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p.at(a).at(b) = true;
    p.at(b).at(a) = true;
  }
  vector<int> v;
  rep(i, N) v.push_back(i);
  int result = 0;
  do {
    if (v.at(0) != 0) continue;

    bool can = true;
    rep(i, N - 1) {
      int a = v.at(i);
      int b = v.at(i + 1);
      if (!p.at(a).at(b)) {
        can = false;
        break;
      }
    }
    if (can) result++;
  } while (next_permutation(v.begin(), v.end()));

  cout << result << endl;
}

