#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N; long long X, Y;
  cin >> N >> X >> Y;
  vector<long long> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];

  sort(A.begin(), A.end(), greater<>());
  long long sumX = 0;
  int cntX = 0;
  rep(i, N) {
    sumX += A[i];
    cntX++;
    if (sumX > X) break;
  }

  sort(B.begin(), B.end(), greater<>());

  long long sumY = 0;
  int cntY = 0;
  rep(i, N) {
    sumY += B[i];
    cntY++;
    if (sumY > Y) break;
  }
  cout << min(cntY, cntX) << endl;
}

