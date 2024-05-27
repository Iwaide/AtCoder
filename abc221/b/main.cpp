#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S, T;
  cin >> S >> T;
  if (S == T) {
    cout << "Yes" << endl;
    return 0;
  }
  rep(i, S.size() - 1) {
    string Si = S;
    char Ci = S.at(i);
    char Ci2 = S.at(i + 1);
    Si.at(i) = Ci2;
    Si.at(i + 1) = Ci;
    if (Si == T) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}

