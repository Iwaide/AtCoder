#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long A, B, N;
  cin >> A >> B >> N;
  long long x = min(B - 1, N);
  cout << (A * x) / B << endl;
}

