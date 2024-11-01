#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()
template<typename T>
void print_vector(vector<T> &vec) {
  rep(i, vec.size()) {
    if (i != vec.size() - 1) {
      cout << vec[i] << " ";
    } else {
      cout << vec[i] << endl;
    }
  }
}

// int N, K;
// map<int, int> pre_menu;
// vector<int> menu;
// // 1個前と2個前だけ覚えておけばいい
// vector<vector<vector<int>>> memo;
// ll rec(int day, int b, int bb) {
//   if (memo[day][b][bb] != -1) {
//     return memo[day][b][bb];
//   }

//   if (day == N + 1) {
//     return 1;
//   }

//   ll ans = 0;
//   // 決まってたら次行くしか無い
//   int pre = pre_menu[day];
//   if (pre != 0) {
//     if (day > 2 && b == pre && bb == pre) {
//       return 0;
//     }
//     menu.push_back(pre);
//     ans = (ans + rec(day + 1, pre, b)) % 10000;
//     menu.pop_back();
//   } else {
//     // 3種類試す
//     rep2(j, 1, 4) {
//       // 同じメニューは3日連続にできない
//       if (day > 2 && b == j && bb == j) {
//         continue;
//       } else {
//         menu.push_back(j);
//         ans = (ans + rec(day + 1, j, b)) % 10000;
//         menu.pop_back();
//       }
//     }
//   }
//   return memo[day][b][bb] = ans % 10000;
// }

// // 3種類のパスタを作れる
// // N日の晩ごはんの予定を立てる
// // 3日以上連続して同じパスタは選べない
// // N日のうちK日分のパスタは決定済み
// // 晩ごはんは何通りあるか、10000で割った余りを求めよ
// int main() {
//   cin >> N >> K;
//   rep(i, K) {
//     int Ai, Bi;
//     cin >> Ai >> Bi;
//     pre_menu[Ai] = Bi;
//   }
//   // 0日目
//   menu.push_back(0);
//   memo.resize(N + 2, vector<vector<int>>(4, vector<int>(4, -1)));

//   // 普通に再帰のほうが解けそうだけど
//   cout << rec(1, 0, 0) << endl;
// }
int MOD = 10000;
int main() {
  int N, K;
  cin >> N >> K;
  map<int, int> pre_menu;
  rep(i, K) {
    int Ai, Bi;
    cin >> Ai >> Bi;
    Ai--;
    pre_menu[Ai] = Bi;
  }

  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(4, vector<int>(4, 0)));
  dp[0][0][0] = 1;

  rep(i, N) {
    rep(j, 4) {
      rep(k, 4) {
        rep2(l, 1, 4) {
          // 決まってるとき
          int pre = pre_menu[i];
          if (pre != 0 && l != pre) {
            continue;
          }

          if (l != j || k != l) {
            dp[i + 1][l][j] += dp[i][j][k];
            dp[i + 1][l][j] %= MOD;
          }
        }
      }

    }
  }
  ll ans = 0;
  rep2(i, 1, 4) {
    rep2(j, 1, 4) {
      if (dp[N][i][j] == -1) continue;
      ans += dp[N][i][j];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
