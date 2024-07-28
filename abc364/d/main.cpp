#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, Q; cin >> N >> Q;
  vector<long long> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());

  rep(i, Q) {
    long long bj; int kj;
    cin >> bj >> kj;

    // Xの範囲内に点がkj個以上あるかどうか
    auto f = [&](int x) -> bool {
      auto lb = lower_bound(A.begin(), A.end(), bj - x);
      auto ub = upper_bound(A.begin(), A.end(), bj + x);
      return ub - lb >= kj;
    };

    // 距離も２分探索する
    int ng = -1, ok = (int) 2e8 + 10;
    while(ok - ng > 1) {
      int mid = (ok + ng) / 2;
      if (f(mid)) ok = mid;
      else ng = mid;
    }
    cout << ok << endl;
  }
}
