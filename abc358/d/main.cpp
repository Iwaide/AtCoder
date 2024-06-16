#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  vector<long long> B(M);
  rep(i, N) cin >> A.at(i);
  rep(i, M) cin >> B.at(i);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  long long result = 0;
  int indexA = 0;
  rep(i, M) {
    long long Bi = B.at(i);
    bool can = false;
    for(int j = indexA; j < N; j++) {
      if (A.at(j) >= Bi) {
        result += A.at(j);
        can = true;
        indexA = j + 1;
        break;
      }
    }
    if (!can) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << result << endl;
}

