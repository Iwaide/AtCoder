#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  rep(i, 3) {
    if (!isdigit(S.at(i))) {
      cout << "error" << endl;
      return 0;
    }
  }
  cout << stoi(S) * 2 << endl;
}

