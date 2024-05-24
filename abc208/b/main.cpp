#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   long long P;
//   cin >> P;
//   int N = 1;
//   int coin = 1;
//   while(P >= coin) {
//     coin *= N;
//     N++;
//   }
//   N--;
//   coin /= N;
//   N--;
//   // cout << coin << ":" << N << endl;
//   int result = 0;
//   while(P > 0) {
//     if (coin > P) {
//       coin /= N;
//       N--;
//     } else {
//       int tmp = P / coin;
//       result += tmp;
//       P -= (tmp * coin);
//     }
//   }
//   cout << result << endl;
// }

int main() {
  long long P;
  cin >> P;
  vector<int> coins(10, 1);
  rep2(i, 1, 10) coins.at(i) = coins.at(i - 1) * (i + 1);
  int result = 0;
  for(int i = 9; i >= 0; i--) {
    while(P >= coins.at(i)) {
      result++;
      P -= coins.at(i);
    }
  }
  cout << result << endl;
}
