#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  pair<double, int> result = { 1000000, 0 };

  rep(i, N) {
    int Hi;
    cin >> Hi;
    double temp = T - ((double) Hi * 6 / 1000);
    if (abs(A - temp) < result.first) {
      result.first = abs(A - temp);
      result.second = i + 1;
    }
  }
  cout << result.second << endl;
}

