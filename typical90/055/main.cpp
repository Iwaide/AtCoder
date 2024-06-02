#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  long long P, Q;
  cin >> P >> Q;
  rep(i, N) cin >>A.at(i);

  int result = 0;
  for(int i = 0; i < N - 4; i++) {
    for(int j = i + 1; j < N - 3; j++) {
      for(int k = j + 1; k < N - 2; k++) {
        for(int l = k + 1; l < N - 1; l++) {
          for(int m = l + 1; m < N; m++) {
            if (A.at(i) * A.at(j) % P * A.at(k) % P * A.at(l) % P * A.at(m) % P == Q) result++;
          }
        }
      }
    }
  }
  cout << result << endl;
}
