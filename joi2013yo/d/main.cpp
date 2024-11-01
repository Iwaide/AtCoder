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

// D日の天気予報をもとに着る服の計画を立てる
// i日目の最高気温はTi度
// N種類の服があり、最高気温が[Aj, Bj]の日に着るのに適している
// 派手さがCj
// 同じ服を何度選んでも良い
// 連続する日に着る服の派手さの差の絶対値の合計をできるだけ大きくする
// D200, N200
// 一旦メモ化再帰で

int D, N;
vector<int> T;
map<int, set<int>> Clothes;
vector<vector<int>> memo;
int rec(int i, int bc) {
  if (memo[i][bc] != -1) return memo[i][bc];

  if (i == D) {
    return 0;
  }

  int ans = 0;
  // T[i]で着られる服ループ
  for(auto ci : Clothes[T[i]]) {
    // 着る、着ない
    chmax(ans, rec(i + 1, ci) + abs(bc - ci));
  }
  return memo[i][bc] = ans;
}

int main() {
  cin >> D >> N;
  T.resize(D);
  memo.resize(D + 1, vector<int>(201, -1));
  rep(i, D) cin >> T[i];
  rep(_, N) {
    int A, B, C;
    cin >> A >> B >> C;
    rep2(i, A, B + 1) {
      Clothes[i].insert(C);
    }
  }
  // 1日目はカウントしない
  int ans = 0;
  for(auto ci : Clothes[T[0]]) {
    chmax(ans, rec(1, ci));
  }

  cout << ans << endl;
}

// scoreはいらないかも
// int main() {
//   int D, N;
//   cin >> D >> N;
//   vector<int> T(D);
//   map<int, set<int>> Clothes;
//   rep(i, D) cin >> T[i];
//   rep(_, N) {
//     int A, B, C;
//     cin >> A >> B >> C;
//     rep2(i, A, B + 1) {
//       Clothes[i].insert(C);
//     }
//   }
//   vector<vector<int>> dp(D + 1, vector<int>(201, -1));
//   // 初期値
//   for(auto ci : Clothes[T[0]]) {
//     dp[1][ci] = 0;
//   }

//   rep(i, D) {
//     for(int ci : Clothes[T[i]]) {
//       rep(j, 201) {
//         if (dp[i][j] == -1) continue;
//         // 着る
//         chmax(dp[i + 1][ci], dp[i][j] + abs(ci - j));
//       }
//     }
//   }
//   int ans = 0;
//   rep(i, 201) chmax(ans, dp[D][i]);
//   cout << ans << endl;
// }
