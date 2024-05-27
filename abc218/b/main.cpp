#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  rep(i, 26) {
    int P;
    cin >> P;
    cout << (char) ('a' + P - 1);
  }
  cout << endl;
}

