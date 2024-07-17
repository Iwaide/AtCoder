#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long x;
  cin >> x;
  int cnt = 0;
  long long d = 0;
  long long tmp = (x - d) / 11LL;
  int mod = (x - d) % 11;
  if (mod == 0) {
    cout << tmp * 2 << endl;
  } else {
    d = tmp * 11 + d;
    if ((x - d) > 6) {
      cout << tmp * 2 + 2 << endl;
    } else {
      cout << tmp * 2 + 1 << endl;
    }
  }
}
