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

// ある製品には1...N個の工程が必要
// 各工程iについてそれを処理する2種類の機械、Si, Tiが売られている
// Ai個/日、Pi円
// Bi個/日、Qi円
// 予算がX円のとき達成可能な製造能力の最大値
// 普通に実装すると予算ぶんだけ探索する必要があって大変そう
// dpやるんだろうけどキーがわからんな。
// 個数によってdpやって全部足してX円超えなかったとき？
int main() {
  int N, X;
  cin >> N >> X;
  vector<vector<double>> M(N, vector<double>(4));
  rep(i, N) {
    double A, P, B, Q;
    cin >> A >> P >> B >> Q;
    M[i] = { A, P, B, Q };
  }
  // 個数でループ
  rep2(i, 1, 10000001) {
    int total = 0;
    // 各工程
    rep(j, N) {
      auto m = M[j];
      double A = m[0], P = m[1], B = m[2], Q = m[3];
      int cost = INT_MAX;
      // コスパ最大までとったケースと、1個減らして超えるまで足したケース
      double costA = A / P, costB = B / Q;
      // APの機械のほうが安いとき
      if (costA < costB) {
        int costA = 0, costAB = 0;
        // 全部APでまかなったとき
        int numA = (i + A - 1) / A;
        costA = numA * P;
        // numA-1個のAとBでまかなったとき
        int numB = (i - (numA - 1) * A + B - 1) / B;
        costAB = (numA - 1) * P + numB * Q;
        cost = min(costA, costAB);
      } else {
        int costB = 0, costAB = 0;
        // 全部Bでまかなったとき
        int numB = (i + B - 1) / B;
        costB = numB * Q;
        // numA-1個のBとAでまかなったとき
        numB--;
        int numA = (i - numB * B + A - 1) / A;
        costAB = numB * Q + numA * P;
        cost= min(costB, costAB);
      }
      total += cost;
    }
    if (total > X) {
      cout << (i - 1) << endl;
      break;
    }
  }
}
