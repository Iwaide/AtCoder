#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N;
  cin >> N;
  long long denomi = 998244353;
  string S = "";
  rep(i, N) S += to_string(N);

  int keta = min((int)S.size(), 10);
  long long numerator = stoll(S.substr(0, keta));
  S.erase(0, keta);
  long long mod = numerator % denomi;
  while(S.size() > 0) {
    int num = (int) (S.at(0) - '0');
    S.erase(0, 1);
    numerator = mod * 10 + num;
    mod = numerator % denomi;
  }
  cout << mod << endl;
}

