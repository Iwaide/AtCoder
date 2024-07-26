#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   long long A, B;
//   cin >> A >> B;
//   bitset<64> ans(A);
//   if (A % 2 == 0) {
//     long long diff = B - A;
//     int mod = diff % 4;
//     ans = B - mod;
//     if (mod > 0) {
//       for(long long i = B - mod + 1; i <= B; i++) {
//         bitset<64> bi(i);
//         ans ^= bi;
//       }
//     }
//   } else {
//     long long diff = B - A;
//     int mod = diff % 4;
//     ans = A;
//     if (mod > 0) {
//       for(long long i = B - mod + 1; i <= B; i++) {
//         bitset<64> bi(i);
//         ans ^= bi;
//       }
//     }
//   }
//   cout << ans.to_ulong() << endl;
// }
long long oddSolve(long long a) { return (a + 1) % 2; }
long long solve(long long a) {
  if (a % 2 == 1) return oddSolve(a);
  else return oddSolve(a + 1) ^ (a + 1);
}

int main() {
  long long A, B; cin >> A >> B;
  cout << (solve(B) ^ solve(A- 1)) << endl;
}
