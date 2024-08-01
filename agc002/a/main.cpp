#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long a, b;
  cin >> a >> b;

  if (a <= 0 && b >= 0) {
    cout << "Zero" << endl;
    return 0;
  }

  if (a > 0) {
    cout << "Positive" << endl;
  }

  if (a < 0 && b < 0) {
    if ((b - a) % 2 == 1) {
      cout << "Positive" << endl;
    } else {
      cout << "Negative" << endl;
    }
  }
}

