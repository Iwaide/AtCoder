#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// string S;
// vector<bool> dp;
// // erasedream
// // 0123456789
// // dream
// // 01234
// bool rec(int i) {
//   if (i == 0) {
//     return true;
//   }

//   if (i - 7 >= 0 && S.substr(i - 7, 7) == "dreamer" && rec(i - 7)) {
//     return true;
//   }
//   if (i - 6 >= 0 && S.substr(i - 6, 6) == "eraser" && rec(i - 6)) {
//     return true;
//   }
//   if (i - 5 >= 0 && S.substr(i - 5, 5) == "dream" && rec(i - 5)) {
//     return true;
//   }
//   if (i - 5 >= 0 && S.substr(i - 5, 5) == "erase" && rec(i - 5)) {
//     return true;
//   }
//   return false;
// }

// int main() {
//   cin >> S;
//   vector<string> words = {
//     "dream",
//     "dreamer",
//     "erase",
//     "eraser"
//   };
//   bool can = rec(S.size());
//   cout << (can ? "YES" : "NO") << endl;
// }

string S;
int main() {
  cin >> S;
  vector<bool> dp(S.size() + 1);
  dp[0] = true;
  for(int i = 1; i <= S.size(); i++) {
    if (i >= 5) {
      dp[i] = dp[i] || (dp[i-5] && S.substr(i-5, 5) == "dream");
    }
    if (i >= 5) {
      dp[i] = dp[i] || (dp[i-5] && S.substr(i-5, 5) == "erase");
    }
    if (i >= 6) {
      dp[i] = dp[i] || (dp[i-6] && S.substr(i-6, 6) == "eraser");
    }
    if (i >= 7) {
      dp[i] = dp[i] || (dp[i-7] && S.substr(i-7, 7) == "dreamer");
    }
  }
  cout << (dp[S.size()] ? "YES" : "NO") << endl;
}

