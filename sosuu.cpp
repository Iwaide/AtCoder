#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<int> sosuu;

bool is_sosuu(int n) {
  bool mod0 = false;
  rep2(i, 2, (int) floor(sqrt((float) n)) + 1) {
    if (is_sosuu(i) && n % i == 0) {
      mod0 = true;
      break;
    }
  }
  return !mod0;
}

int main() {
  int n;
  cin >> n;
  cout << (is_sosuu(n) ? "Yes" : "No") << endl;;
}

