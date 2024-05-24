#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  long long result = 0;
  rep2(i, 1, N + 1) {
    if (i % 3 != 0 && i % 5 != 0) result += i;
  }
  cout << result << endl;
}
