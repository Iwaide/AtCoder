#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N; cin >> N;
  vector<long long> A(N);
  rep(i, N) cin >> A[i];
  vector<long long> sorted = A;
  sort(sorted.begin(), sorted.end());
  long long second = sorted[N - 2];
  rep(i, N) {
    if (A[i] == second) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}

