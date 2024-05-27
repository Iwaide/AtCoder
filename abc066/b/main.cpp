#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  int result = 0;
  int is_even = false;
  while(!is_even) {
    if (result != 0 && S.size() % 2 == 0) {
      if (S.substr(0, S.size() / 2) == S.substr(S.size() / 2, S.size() / 2)) {
        is_even = true;
      }
    }
    if (!is_even) {
      result++;
      S = S.substr(0, S.size() - 1);
    }
  }
  cout << S.size() << endl;
}

