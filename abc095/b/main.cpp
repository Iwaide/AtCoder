#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  int min_m = 1000;
  int result = 0;
  rep(i, N) {
    int mi;
    cin >> mi;
    X -= mi;
    result++;
    min_m = min(min_m, mi);
  }
  result += X / min_m;
  cout << result << endl;
}

