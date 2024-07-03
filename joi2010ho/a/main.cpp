#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int m, n;
  cin >> n >> m;
  vector<long long> cs(n, 0);
  rep(i, n - 1) {
    long long si;
    cin >> si;
    cs.at(i + 1) = cs.at(i) + si;
  }
  int current = 0;
  long long result = 0;
  rep(i, m) {
    int ai; cin >> ai;
    if (ai > 0) {
      result += cs.at(current + ai) - cs.at(current);
      current += ai;
    } else {
      result += cs.at(current) - cs.at(current + ai);
      current += ai;
    }
    result = result % 100000LL;
  }
  cout << result % 100000LL << endl;
}

