#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<char> S(N);
  rep(i, N) cin >> S.at(i);

  int result = 0;
  rep2(i, 1, N - 1) {
    set<char> X;
    set<char> Y;
    rep(j, N) {
      if (j < i) {
        X.insert(S.at(j));
      } else {
        Y.insert(S.at(j));
      }
    }
    int counter = 0;
    for(char x: X) {
      for(char y: Y) {
        if (x == y) {
          counter++;
          break;
        }
      }
    }
    result = max(result, counter);
  }
  cout << result << endl;
}

