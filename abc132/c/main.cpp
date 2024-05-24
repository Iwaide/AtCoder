#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N) cin >> d.at(i);
  sort(d.begin(), d.end());
  cout << (d.at(N / 2) - d.at(N / 2 - 1)) << endl;
}

