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

// int N; string S;
// string txt = "atcoder";
// vector<vector<int>> memo;
// ll rec(int i, int j) {
//   if (memo[i][j] != -1) return memo[i][j];
//   // atcoderの0始まり
//   if (j == 7) return 1;
//   if (i == N) return 0;

//   ll ans = rec(i + 1, j);
//   if (S[i] == txt[j]) {
//     ans = (ans + rec(i + 1, j + 1)) % 1000000007;
//   }
//   return memo[i][j] = ans;
// }
// // 英小文字のみからなるS(|N|)
// // Sのi文字目をsiとする
// // Sから0個以上の文字を取り出す方法は2^N通りあるがそのうち以下の条件を満たすものは何通りか
// // 10^9+7で割った余りを求めよ
// // 取り出した文字を順番を変えずに結合してできた文字列がatcoderとなる
// int main() {
//   cin >> N >> S;
//   memo.resize(N + 1, vector<int>(8, -1));
//   // 普通に解くと
//   cout << rec(0, 0) << endl;
// }


// DPで解く
int MOD = 1000000007;
int main() {
  int N; string S;
  cin >> N >> S;

  vector<vector<int>> dp(8, vector<int>(N + 1, 0));
  dp[0][0] = 1;
  string text = "atcoder";
  // iが7までやらないといけないのなんで？
  rep(i, 8) {
    rep(j, N) {
      // 選ばないとき
      dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
      // 選ぶとき
      if (text[i] == S[j]) {
        dp[i + 1][j + 1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
      }
    }
  }
  cout << dp[7][N] % 1000000007 << endl;
}