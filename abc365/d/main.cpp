// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int N;
// string S;

// char win(char c) {
//     if (c == 'R') return 'P';
//     else if (c == 'P') return 'S';
//     else return 'R';
// }

// // 幅優先探索
// int rec(int index, char before_hand) {
//   char win_hand = win(S[index]);
//   if (index == S.size() - 1) {
//     if (win_hand == before_hand) {
//       return 0;
//     } else {
//       return 1;
//     }
//   }

//   int ans1 = -1;
//   if (win_hand != before_hand) {
//     ans1 = 1 + rec(index + 1, win_hand);
//   }
//   int ans2 = -1;
//   if (S[index] != before_hand) {
//     ans2 = 0 + rec(index + 1, S[index]);
//   }
//   return max(ans1, ans2);
// }

// vector<vector<char>> dp;
// int main() {
//   cin >> N >> S;

//   int ans1 = rec(0, 'N');
//   cout << ans1 << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int N;
// string S;
// vector<vector<int>> dp;

// char win(char c) {
//     if (c == 'R') return 'P';
//     else if (c == 'P') return 'S';
//     else return 'R';
// }

// // メモ化再帰
// int rec(int index, char before_hand) {
//     if (dp[index][before_hand - 'A'] != -1) return dp[index][before_hand - 'A'];

//     char win_hand = win(S[index]);
//     if (index == S.size() - 1) {
//         if (win_hand == before_hand) {
//             return dp[index][before_hand - 'A'] = 0;
//         } else {
//             return dp[index][before_hand - 'A'] = 1;
//         }
//     }

//     int ans1 = -1;
//     if (win_hand != before_hand) {
//         ans1 = 1 + rec(index + 1, win_hand);
//     }
//     int ans2 = -1;
//     if (S[index] != before_hand) {
//         ans2 = 0 + rec(index + 1, S[index]);
//     }
//     return dp[index][before_hand - 'A'] = max(ans1, ans2);
// }

// int main() {
//     cin >> N >> S;

//     // dpを初期化する。各要素は-1で初期化される
//     dp.assign(N, vector<int>(26, -1)); // 26はアルファベットの数

//     int ans1 = rec(0, 'N'); // 'N'は初期状態で使われるダミー文字
//     cout << ans1 << endl;
// }

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int N;
string S;
vector<map<char, int>> dp;

char win(char c) {
    if (c == 'R') return 'P';
    else if (c == 'P') return 'S';
    else return 'R';
}

int main() {
  cin >> N >> S;
  dp.resize(N);
  rep(i, N) {
    dp.push_back(
      map<char, int> {
        { 'P', -1 },
        { 'R', -1 },
        { 'S', -1 },
      }
    );
  }
  char first_hand = S[0];
  dp[0][first_hand] = 0;
  dp[0][win(first_hand)] = 1;
  vector<char> hands{ 'R', 'P', 'S' };
  rep2(i, 1, N) {
    char s = S[i];

    rep(j, hands.size()) {
      char hand = hands[j];
      int tmp = INT_MIN;
      // あいこのとき
      if (hand != s) {
        tmp = max(tmp, dp[i - 1][hand]);
      }
      dp[i][s] = max(dp[i][s], tmp);
      // 勝ちのとき
      char win_hand = win(s);
      tmp = INT_MIN;
      if (hand != win_hand) {
        tmp = max(tmp, dp[i - 1][hand]) + 1;
      }
      dp[i][win_hand] = max(dp[i][win_hand], tmp);
    }
  }
  cout << max(dp[N - 1]['P'], max(dp[N - 1]['R'], dp[N - 1]['S'])) << endl;
}
