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

// 数字の形をしたキャンドルがついたケーキを販売している
// 1, 2, 3ノカタチをいたキャンドルがついたケーキがそれぞれX, Y, Z種類ある
// それぞれのケーキには美味しさが割り当てられている
// 3つのケーキの美味しさの合計が大きい順に並べたとき、1, 2, K番目の選び方でのケーキの美味しさの合計をそれぞれ出力せよ
// using cakes = tuple<ll, int, int, int>;
// int main() {
//   ll X, Y, Z, K;
//   cin >> X >> Y >> Z >> K;

//   vector<ll> A(X), B(Y), C(Z);

//   rep(i, X) cin >> A[i];
//   rep(i, Y) cin >> B[i];
//   rep(i, Z) cin >> C[i];
//   sort(all(A), greater<ll>()), sort(all(B), greater<ll>()), sort(all(C), greater<ll>());
//   priority_queue<cakes> Q;
//   vector<vector<vector<bool>>> added(X, vector<vector<bool>>(Y, vector<bool>(Z, false)));
//   added[0][0][0] = true;
//   Q.push({ A[0] + B[0] + C[0], 0, 0, 0 });
//   rep(i, K) {
//     auto q = Q.top(); Q.pop();
//     cout << get<0>(q) << endl;
//     int x = get<1>(q), y = get<2>(q), z = get<3>(q);
//     if (x + 1 < X && !added[x + 1][y][z]) {
//       Q.push({ A[x + 1] + B[y] + C[z], x + 1, y, z });
//       added[x + 1][y][z] = true;
//     }
//     if (y + 1 < Y && !added[x][y + 1][z]) {
//       Q.push({ A[x] + B[y + 1] + C[z], x, y + 1, z });
//       added[x][y + 1][z] = true;
//     }
//     if (z + 1 < Z && !added[x][y][z + 1]) {
//       Q.push({ A[x] + B[y] + C[z + 1], x, y, z + 1 });
//       added[x][y][z + 1] = true;
//     }
//   }
// }

int main() {
  ll X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X), B(Y), C(Z);
  rep(i, X) cin >> A[i];
  rep(i, Y) cin >> B[i];
  rep(i, Z) cin >> C[i];
  // vector<ll> AB;
  // rep(i, X) {
  //   rep(j, Y) {
  //     AB.push_back(A[i] + B[j]);
  //   }
  // }
  // sort(all(AB), greater<ll>());
  // sort(all(C), greater<ll>());
  // vector<ll> ans;
  // rep(i, min(K, X * Y)) {
  //   rep(j, min(Z, K)) {
  //     ans.push_back(AB[i] + C[j]);
  //   }
  // }
  // sort(all(ans), greater<ll>());
  // rep(i, K) cout << ans[i] << endl;
  sort(all(A), greater<ll>());
  sort(all(B), greater<ll>());
  sort(all(C), greater<ll>());
  vector<ll> ans;
  rep(i, X) {
    rep(j, Y) {
      rep(k, Z) {
        if ((i + 1) * (j + 1) * (k + 1) <= K) ans.push_back(A[i] + B[j] + C[k]);
        else break;
      }
    }
  }
  sort(all(ans), greater<ll>());
  rep(i, K) cout << ans[i] << endl;
}