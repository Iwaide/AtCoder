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
  // int i;
  // cin >> i;
  // cout << is_prime(i);
  vector<int> cul(100001, 0);
  for(int i = 3; i <= 100000; i++) {
    int tmp = 0;
    if (i % 2 == 1) {
      if (is_prime(i) && is_prime((i + 1) / 2)) {
        tmp = 1;
      }
    }
    cul.at(i) = cul.at(i - 1) + tmp;
  }
  int Q;
  cin >> Q;
  rep(i, Q){
    int l, r; cin >> l >> r;
    cout << cul.at(r) - cul.at(l - 1) << endl;
  }
}

/*
    1 2 3 4 5 6 7 8 9 10 11
  0 0 0 1 0 1 0 0 0 0 0  0 
  0 0 0 1 1 2 2 2 2 2 2  2

*/