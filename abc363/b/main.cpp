#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, T, P;
  cin >> N >> T >> P;
  vector<int> L(N);
  rep(i, N) {
    cin >> L[i];
  }
  rep(i, 200) {
    int cnt = 0;
    rep(j, N) {
      int Li = L[j] + i;
      if (Li >= T) {
        cnt++;
      }
    }
    if (cnt >= P) {
      cout << i << endl;
      return 0;
    }
  }
}

