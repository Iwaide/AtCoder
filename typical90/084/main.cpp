#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> a;
  long long result = 1LL * N * (N - 1) / 2;
  for(int i = 0; i < S.size();) {
    int j = i + 1;
    while(j < S.size() && S.at(i) == S.at(j)) j++;
    long long cnt = j - i;
    result -= cnt * (cnt - 1) / 2;
    i = j;
  }
  cout << result << endl;
}

