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

// N行N列のグリッド
// グリッドは黒#白.で構成
// i = 1, 2... N/2の順に以下の操作を行ったあとのグリッドの各マスの色
// i以上 N + 1 - i以下の整数x, yについて、ます(y, N + 1 - x)の色を(x, y)の色で置き換える
// この置き換えは条件を満たすすべての整数x, yについて同時に行う
// 4回操作を行うと元に戻るので、各マスについて最大3回の操作を行えばよい
// x, yのあるiの個数はmin(x, N + 1 - x, y, N + 1 - y)で求められる
int main() {
  int N; cin >> N;
  vector<vector<char>> A(N, vector<char>(N));
  rep(i, N) rep(j, N) cin >> A[i][j];

  vector<vector<char>> B(N, vector<char>(N));
  rep(x, N) {
    rep(y, N) {
      // iの回数, 0始まりにしてるので各回+1
      int cnt = min({x + 1, N - x, y + 1, N - y});
      int nextX = x, nextY = y;
      rep(_, cnt % 4) {
        int tmpx = nextY, tmpy = N - 1- nextX;
        nextX = tmpx, nextY = tmpy;
      }
      B[nextX][nextY] = A[x][y];
    }
  }
  rep(i, N) {
    rep(j, N) {
      cout << B[i][j];
    }
    cout << endl;
  }
}
