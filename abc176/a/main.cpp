#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, X, T;
  cin >> N >> X >> T;
  cout << ((N + X - 1) / X) * T << endl;
}

