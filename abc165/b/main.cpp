#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long X;
  cin >> X;
  long long bank = 100;
  long long i = 0;
  while(bank < X) {
    bank += bank / 100;
    i++;
  }
  cout << i << endl;
}

