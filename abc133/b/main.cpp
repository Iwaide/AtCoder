#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  rep(i, N) {
    vector<int> Xi(D);
    rep(i, D) cin >> Xi.at(i);
    X.at(i) = Xi;
  }
  int result = 0;
  for(int i = 0; i < N; i++) {
    vector<int> y = X.at(i);
    for(int j = i + 1; j < N; j++) {
      vector<int> z = X.at(j);
      int distance = 0;
      rep(k, D) {
        distance += (y.at(k) - z.at(k)) * (y.at(k) - z.at(k));
      }
      if (sqrt(distance) == (int) sqrt(distance)) result++;
    }
  }
  cout << result << endl;
}

