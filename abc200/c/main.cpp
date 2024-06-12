#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  map<int, int> A;
  rep(i, N) {
    long long Ai;
    cin >> Ai;
    int modA = Ai % 200;
    A[modA] += 1;
  }
  long long result = 0;
  for(auto pair: A) {
    result += 1LL * pair.second * (pair.second - 1) / 2;
  }
  cout << result << endl;
}

