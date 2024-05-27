#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  int result = 0;
  for(int i = 0; i < S.size() / 2; i++) {
    if (S.at(i) != S.at(S.size() - 1 - i)) {
      result++;
    }
  }
  cout << result << endl;
}

