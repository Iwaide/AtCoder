#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  // if (N % 1000 == 0) {
  //   cout << 0 << endl;
  // } else {
  //   cout << (1000 - (N % 1000)) << endl;
  // }
  // cout << (1000 - (N % 1000)) % 1000 << endl;
  cout << ((10000 - N) % 1000) << endl;
}

