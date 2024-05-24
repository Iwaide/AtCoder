#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int counter = 0;
  rep(i, A + 1) {
    rep(j, B + 1) {
      rep(k, C + 1) {
        int total = 500 * i+ 100 * j + 50 * k;
        if (total == X) {
          counter++;
        }
      }
    }
  }
  cout << counter << endl;
}
