#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int plan1 = N * A;
  if (plan1 > B) {
    cout << B << endl;
  } else {
    cout << plan1 << endl;
  }
}
