#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int i = 0;
  while(!(A <=0 || C <= 0)) {
    if (i % 2 == 0) {
      C -= B;
    } else {
      A -= D;
    }
    i++;
  }
  cout << (C <= 0 ? "Yes" : "No") << endl;
}

