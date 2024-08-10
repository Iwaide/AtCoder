#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// N, N, Nの3次元配列が与えられる
// クエリでは、Lx~Rx, Ly~Ry, Lz~Rzの合計を出す
// 3次元累積和の問題っぽい
int main() {
  int N; cin >> N;
  vector<vector<vector<int>>> A(N, vector<vector<int>>(N, vector<int>(N)));
  rep(i, N){
    rep(j, N) {
      rep(k, N) {
        cin >> A[i][j][k];
      }
    }
  }
  vector<vector<vector<int>>> sum(N+1, vector<vector<int>>(N+1, vector<int>(N+1, 0)));
  rep2(i, 1, N+1) {
    rep2(j, 1, N+1) {
      rep2(k, 1, N+1) {
        sum[i][j][k] = A[i-1][j-1][k-1]
          + sum[i-1][j][k]
          + sum[i][j-1][k]
          + sum[i][j][k-1]
          - sum[i-1][j-1][k]
          - sum[i][j-1][k-1]
          - sum[i-1][j][k-1]
          + sum[i-1][j-1][k-1];
      }
    }
  }
  int Q; cin >> Q;
  rep(_, Q) {
    int Lx, Rx, Ly, Ry, Lz, Rz;
    cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;

    int result = sum[Rx][Ry][Rz]
            - sum[Lx-1][Ry][Rz]
            - sum[Rx][Ly-1][Rz]
            - sum[Rx][Ry][Lz-1]
            + sum[Lx-1][Ly-1][Rz]
            + sum[Lx-1][Ry][Lz-1]
            + sum[Rx][Ly-1][Lz-1]
            - sum[Lx-1][Ly-1][Lz-1];

    cout << result << endl;
  }
}

