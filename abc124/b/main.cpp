#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, N) cin >> H.at(i);
  int result = 0;
  int max_H = 0;
  rep(i, N) {
    if (max_H <= H.at(i)) {
      result++;
    }
    max_H = max(max_H, H.at(i));
  }
  cout << result << endl;
}

