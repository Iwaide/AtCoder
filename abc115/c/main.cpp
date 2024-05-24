#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> h(N);
  rep(i, N) cin >> h.at(i);
  sort(h.begin(), h.end());
  long long result = 1e9;
  rep(i, N - (K - 1)) {
    long long h_min = h.at(i);
    long long h_max = h.at(i + K - 1);
    result = min(result, h_max - h_min);
  }
  cout << result << endl;
}

