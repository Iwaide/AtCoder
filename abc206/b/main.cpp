#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int tmp = 0;
  int i = 1;
  while(tmp < N) {
    tmp += i;
    i++;
  }
  cout << (i - 1) << endl;
}

