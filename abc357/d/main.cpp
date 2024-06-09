#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   long long N;
//   cin >> N;
//   long long denomi = 998244353;
//   string S = "";
//   rep(i, N) S += to_string(N);

//   int keta = min((int)S.size(), 10);
//   long long numerator = stoll(S.substr(0, keta));
//   S.erase(0, keta);
//   long long mod = numerator % denomi;
//   while(S.size() > 0) {
//     int num = (int) (S.at(0) - '0');
//     S.erase(0, 1);
//     numerator = mod * 10 + num;
//     mod = numerator % denomi;
//   }
//   cout << mod << endl;
// }

// Nの繰り返しは等比数列の和
// e.g 123123123....
// 123 + 123 * 1000 ^ 1 + 123 * 1000 ^2
// 1 + r + r^2 + r^3 ... = 1 - r ^ n / 1 - r
// 123(1 - 1000 ^ 123) / 1 - 1000
// 等比数列の和
// 元のSから公比rをかけたものを引く
// S - rS = a - a * r ^ n
//  S = a - a * r ^ n / 1 - r = a(1 - r ^ n) / (1 - r)
// その後はよくわからんかった。D問題だから一旦とばして教科書とかで勉強しよ…
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


