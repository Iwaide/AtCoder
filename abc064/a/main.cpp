#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  cout << ((g * 10 + b) % 4 == 0 ? "YES" : "NO") << endl;
}

