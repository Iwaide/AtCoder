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

// 長さNの正数列 A1, A2,,AN
// l, rを取って等差数列であるようなもの
// 3, 6, 9, 3
// 3, 3, -6
// 87 42 64 86 72 58 44 30
// -45, 22, 22, -14, -14, -14, -14
// l=r以外のときは差分取って、掛け算して足していったらいい気がする
int main() {
  int N; cin >> N;
  vector<long long> A(N);

  rep(i, N) cin >> A[i];

  long long ans = 0;
  // (i, i)のときは必ず等差数列
  ans += N;

  for(int i = 0; i < N - 1;) {
    int j = i + 1;
    long long diff = A[j] - A[i];
    // 違う差分に行き着くまでjを進める
    while((A[j + 1] - A[j]) == diff) j++;
    long long cnt = j - i;
    ans += (cnt + 1) * (cnt) / 2;
    i = j;
  }

  cout << ans << endl;
}

