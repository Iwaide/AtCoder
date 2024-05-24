#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int count = 100;
  rep(i, N) {
    int A;
    cin >> A;
    int x = 0;
    while(A % 2 == 0 && count != 0) {
      x++;
      A /= 2;
    }
    if (x < count) {
      count = x;
    }
  }
  cout << count << endl;
}
