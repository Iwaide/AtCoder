#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N;
  cin >> N;
  if (N <= 10) {
    cout << N - 1 << endl;
    return 0;
  }
  pair<long long, long long> sum(10, 10);
  int digit = 2;
  while(sum.second <= N) {
    long long tmp = 0;
    rep(i, digit / 2) {
      if (i == 0) {
        tmp = 9;
      } else {
        tmp *=10;
      }
    } 
    if (digit % 2 != 0) {
      tmp *= 10;
    }
    sum.first = sum.second;
    sum.second += tmp;
    digit++;
  }
  digit--;
  N -= sum.first;

  while(N >= )
  cout << digit << " " << sum.first << endl;
}

