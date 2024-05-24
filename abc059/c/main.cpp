#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (long long i = (s); i < (long long)(n); i++)

long long N;

// opが1は奇数のときに+偶数のときに-
long long check(vector<long long> &a, long long op) {
  long long result = 0;
  long long sum = 0;
  rep(i, N) {
    sum += a.at(i);
    if (i % 2 == op && !(sum > 0)) {
      long long tmp = 1 - sum;
      result += abs(tmp);
      sum += tmp;
    } else if (i % 2 != op && !(sum < 0)){
      long long tmp = -1 - sum;
      result += abs(tmp);
      sum += tmp;
    }
  }
  return result;
}

int main() {
  cin >> N;
  vector<long long> a(N);
  rep(i, N) cin >> a.at(i);

  cout << min(check(a, 0), check(a, 1)) << endl;
}

