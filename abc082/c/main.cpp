#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  map<long long, int> a;
  rep(i, N) {
    long long ai;
    cin >> ai;
    a[ai] += 1;
  }
  int result = 0;
  for(auto pair: a) {
    if (pair.first == pair.second) continue;
    if (pair.second < pair.first) {
      result += pair.second;
    } else {
      result += (pair.second - pair.first);
    }
  }
  cout << result << endl;
}

