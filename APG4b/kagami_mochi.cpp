#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> mochis(N);
  rep(i, N) cin >> mochis.at(i);
  sort(mochis.begin(), mochis.end());
  mochis.erase(unique(mochis.begin(), mochis.end()), mochis.end());
  cout << mochis.size() << endl;
}
