#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  string S;
  long long K;
  cin >> S >> K;
  vector<int> a;
  for(int i = 0; i < S.size();) {
    int j = i + 1;
    while(j < S.size() && S.at(i) == S.at(j)) j++;
    a.push_back(j - i);
    i = j;
  }
  if (a.size() == 1) {
    cout << (long long) S.size() * K / 2 << endl;
    return 0;
  }

  if (S.at(0) != S.back()) {
    long long cnt = 0;
    for(auto ai: a) cnt += ai / 2;
    cout << cnt * K << endl;
  } else {
    int first = a.at(0);
    int last = a.back();
    a.at(0) = 0;
    a.back() = 0;
    long long cnt = 0;
    for (auto ai: a) cnt += ai / 2;
    long long result = cnt * K;
    result += (first + last) / 2 * (K - 1);
    result += first / 2;
    result += last / 2;
    cout << result << endl;
  }
}
