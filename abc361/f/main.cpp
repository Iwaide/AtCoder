#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

bool is_prime(int n) {
  int sn = (int) floor(sqrt(n));
  bool is = true;
  for(int i = 2; i <= sn; i++) {
    if (n % i == 0) {
      is = false; break;
    }
  }
  return is;
}

int main() {
  long long N;
  cin >> N;
  long long res = 1;
  rep2(i, 2, sqrt(N)) {
    if (is_prime(i)) {
      long long tmp =  max(0LL, (long long)(log2(N) / log2(i)) - 1);
      res += tmp;
    }
  }
  cout << res << endl;
  // cout << sqrt(99) << endl;
  // cout << log2(99) << endl;
}

