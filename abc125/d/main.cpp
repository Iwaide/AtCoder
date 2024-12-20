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

// N個の整数が並んでいる
// 次の操作を好きなだけ行う
// 1 <= i <= N - 1を満たす整数iを選ぶ、Ai と Ai + 1に-1を乗算する
// 操作後の数列の最大値を求めよ
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll minus_cnt = 0, abs_min = LONG_LONG_MAX, sum = 0;
  rep(i, N) {
    cin >> A[i];
    if (A[i] < 0) {
      minus_cnt++;
    }
    chmin(abs_min, abs(A[i]));
    sum += abs(A[i]);
  }
  if (minus_cnt % 2) {
    cout << sum - (abs_min * 2) << endl;
  } else {
    cout << sum << endl;
  }
}

