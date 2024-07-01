#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<int> cul(N + 1, 0);
  rep2(i, 1, N + 1) {
    cul[i + 1] = cul[i] + (S.substr(i - 1, 2) == "AC" ? 1 : 0);
  }
  rep(i, Q) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << cul[r] - cul[l + 1] << endl;
  }
}

