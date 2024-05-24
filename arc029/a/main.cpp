#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> t(N);
  rep(i, N) cin >> t.at(i);
  int result = 10000;
  rep(i, (1 << N)) {
    bitset<4> combination(i);
    int A = 0;
    int B = 0;
    rep(j, N) {
      if (combination.test(j)) {
        A += t.at(j);
      } else {
        B += t.at(j);
      }
    }
    result = min(result, max(A, B));
  }
  cout << result << endl;
}

