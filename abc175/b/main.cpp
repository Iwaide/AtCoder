#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<long long> L(N);
  rep(i, N) cin >> L.at(i);
  sort(L.begin(), L.end());
  int result = 0;
  for(int i = 0; i < N - 2; i++) {
    int Li = L.at(i);
    for (int j = i + 1; j < N - 1; j++) {
      if (j >= N) continue;

      int Lj = L.at(j);
      for(int k = j + 1; k < N; k++) {
        if (k >= N) continue;

        int Lk = L.at(k);
        if (Li != Lj && Lj != Lk && Li != Lk) {
          if (Li + Lj > Lk) {
            result++;
          }
        }
      }
    }
  }
  cout << result << endl;
}

