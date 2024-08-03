#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// イベントにN人が参加 i番目の人の交通費Ai
// 交通費補助額min(x, Ai)を支給
// 予算はM円、N人に渡す交通費補助額の総和をM円以下にしたいときxを最大いくらにできるか
// 交通費補助額を無限に大きくできるときはinfiniteと出力する
// Nは2 * 10 ^ 5
int main() {
  int N; long long M;
  cin >> N >> M;
  vector<long long> A(N);
  long long maximum = 0;
  rep(i, N) {
    cin >> A[i];
    maximum = max(A[i], maximum);
  }
  long long total = accumulate(A.begin(), A.end(), (long long) 0);
  // 合計額が予算以下であればinfiniteにできる
  if (M >= total) {
    cout << "infinite" << endl;
    return 0;
  }

  // 2分探索で探してみる
  long long ok = 0;
  long long ng = maximum;
  while(ng - ok > 1) {
    long long mid = (ok + ng) / 2;
    long long hozyo = 0;
    rep(i, N) {
      hozyo += min(mid, A[i]);
    }
    if (hozyo > M) {
      ng = mid;
    } else {
      ok = mid;
    }
  }
  cout << ok << endl;
}

