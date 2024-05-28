#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a, b;
  cin >> a >> b;
  vector<string> S(2);
  rep(i, b) S.at(0) += to_string(a);
  rep(i, a) S.at(1) += to_string(b);
  sort(S.begin(), S.end());
  cout << S.at(0) << endl;
}

