#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// 解けたけどなんかよくわからん解き方になった
// int main() {
//   int N, K;
//   cin >> N >> K;
//   long long result = 0;
//   for (int a = 1; a <= N; a++) {
//     int rest_a = a % K;
//     int b_start = K - rest_a;
//     if (b_start == 0) b_start = K;
//     if ((b_start % K) != rest_a) continue;
//     result += 1LL * ((N - b_start) / K + 1) * ((N - b_start) / K + 1);
//   }
//   cout << result << endl;
// }

int main() {
  int N, K;
  cin >> N >> K;
  long long m0 = 0;
  rep2(i, 1, N + 1) if (i % K == 0) m0++; 
  long long ans = m0 * m0 * m0;

  if (K % 2 == 0) {
    long long c = 0;
    rep2(i, 1, N + 1) if (i % K == K / 2) c++;
    ans += c * c * c;
  }
  cout << ans << endl;
}