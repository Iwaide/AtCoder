#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> l(N);
  rep(i, N) cin >> l.at(i);
  sort(l.begin(), l.end(), greater<int>());
  int result = 0;
  rep(i, K) result += l.at(i);
  cout << result << endl;
}

