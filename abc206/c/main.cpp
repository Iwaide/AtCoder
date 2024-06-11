#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// 余事象を引く解き方
// Ai == Ajとなるものを引くので、AmapのnC2を引けば良い
// int main() {
//   int N;
//   cin >> N;
//   map<long long, long long> Amap;
//   rep(i, N) {
//     long long A;
//     cin >> A;
//     Amap[A] += 1;
//   }
//   long long result = 1LL * N * (N - 1) / 2;
//   for(auto pair : Amap) {
//     if (pair.second > 1) {
//       result -= pair.second * (pair.second - 1) / 2;
//     }
//   }
//   cout << result << endl;
// }

// 数列を変換するような考え方
// 同じ数があるとき、数列自体が圧縮されて少なくなると考える
// A = {1, 1, 2, 3, 3 }のようなとき、各数字に対する組み合わせ
// ((5 - 2) + (5 - 2) + (5 - 1) + (5 - 2) + (5 - 2)) / 2で求める
int main() {
  int N;
  cin >> N;
  vector<long long> A;
  map<long long, long long> Amap;
  rep(i, N) {
    long long Ai;
    cin >> Ai;
    A.push_back(Ai);
    Amap[Ai] += 1;
  }
  long long result = 0;
  for(long long Ai : A) {
    result += N - Amap[Ai];
  }
  result /= 2;
  cout << result << endl;
}
