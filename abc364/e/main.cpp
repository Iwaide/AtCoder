#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

void chmin(int &a, int b) { a = min(a, b); }

// 普通にdpやったとき
// int main()
// {
//   int N, X, Y;
//   vector<pair<int, int>> foods;
//   cin >> N >> X >> Y;
//   vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(X + 1, vector<int>(Y + 1, 0)));

//   rep(i, N) {
//     int A, B;
//     cin >> A >> B;
//     foods.push_back(make_pair(A, B));
//   }

//   for (int i = 1; i <= N; ++i) {
//     for (int j = 0; j <= X; ++j) {
//       for (int k = 0; k <= Y; ++k) {
//         // 料理 i を選ばない場合
//         dp[i][j][k] = dp[i - 1][j][k];
//         auto food = foods[i - 1];

//         // 料理 i を選ぶ場合
//         if (j >= food.first && k >= food.second)
//         {
//           dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - food.first][k - food.second] + 1);
//         }
//       }
//     }
//   }
//   int max_dishes = 0;
//   for (int j = 0; j <= X; ++j) {
//     for (int k = 0; k <= Y; ++k) {
//         max_dishes = max(max_dishes, dp[N][j][k]);
//     }
//   }

//   cout << min(max_dishes + 1, N) << endl;
// }

// [i][j][k]だとO(NXY)になって間に合わないので、キーと値を入れ替える
// i個の中から、k個選ぶ、甘さの合計がjとなるときのしょっぱさの合計の最小値にする
int main() {
  int N, X, Y;
  vector<pair<int, int>> foods;
  cin >> N >> X >> Y;
  // 後で足し算するのでINT_MAXだとオーバーフローする
  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(X + 1, 1e9)));

  dp[0][0][0] = 0;
  
  rep(i, N) {
    int A, B;
    cin >> A >> B;
    foods.push_back(make_pair(A, B));
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      for(int k = 0; k <= X; k++) {
        // i個目の料理を選ばなかったとき
        // dp[i + 1]はdp[i]を選んだとき、の値
        chmin(dp[i+1][j][k], dp[i][j][k]);
        // 選ぶとき
        auto food = foods[i];
        if (k + food.first <= X) {
          chmin(dp[i + 1][j + 1][k + food.first], dp[i][j][k] + food.second);
        }
      }
    }
  }
  
  for(int i = N; i >= 0; i--) {
    for(int j = 0; j <= X; j++) {
      if (dp[N][i][j] <= Y) {
        cout << min(i + 1, N) << endl;
        return 0;
      }
    }
  }
}
