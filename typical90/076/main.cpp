#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N; cin >> N;
  vector<long long> A(N);
  rep(i, N) cin >> A[i];
  vector<long long> sum(2 * N + 1);
  rep(i, 2 * N) {
    sum[i + 1] = sum[i] + A[i % N];
  }
  if (sum.at(N) % 10LL != 0) {
    cout << "No" << endl;
    return 0;
  }
  long long div10 = sum[N] / 10LL;

  rep(i, 2 * N + 1) {
    long long sum_i = sum[i];
    long long target = div10 + sum[i];
    if (binary_search(sum.begin(), sum.end(), target)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
