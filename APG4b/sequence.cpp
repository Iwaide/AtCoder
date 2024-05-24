#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long i = 0; i < (long)(n); i++)
#define rep2(i, s, n) for (long i = (s); i < (long)(n); i++)

long N;

long solve(vector<long> nums, long x) {
  long sum = 0;
  long counter = 0;
  rep(i, N) {
    sum += nums.at(i);
    if (i % 2 == x && sum >= 0) {
      long adjustment = -1 - sum;
      sum += adjustment;
      counter += abs(adjustment);
    } else if (i % 2 != 0 && sum <= 0) {
      long adjustment = 1 - sum;
      sum += adjustment;
      counter += abs(adjustment);
    }
  }
  return counter;
}

int main() {
  cin >> N;
  vector<long> nums(N);
  rep(i, N) cin >> nums.at(i);
  cout << min(solve(nums, 0), solve(nums, 1)) << endl;
}


// これ間違ってる
// long main() {
//   long N;
//   cin >> N;
//   vector<long> nums(N);
//   rep(i, N) cin >> nums.at(i);
//   long counter = 0;
//   long prev_sum = 0;
//   long sum = 0;
//   rep(j, N) {
//     sum += nums.at(j);
//     if ((prev_sum > 0 && sum >= 0) || (prev_sum < 0 && sum <= 0)) {
//       long adjustment = (prev_sum > 0 ? -1 : 1) - sum;
//       sum += adjustment;
//       counter += abs(adjustment);
//     }
//     prev_sum = sum;
//   }
//   cout << counter << endl;
// }

