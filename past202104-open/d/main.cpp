#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> cs(N + 1, 0);
  rep(i, N) {
    long long Ai; cin >> Ai;
    cs.at(i + 1) = cs.at(i) + Ai;
  }
  for(int x = 0; x <= N - K; x++) {
    cout << cs.at(x + K) - cs.at(x) << endl;
  }
}

