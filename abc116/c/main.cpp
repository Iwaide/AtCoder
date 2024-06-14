#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  rep(i, N) cin >> h.at(i);

  int result = 0;
  for(int i = 0; i < N;) {
    int j = i + 1;
    int diff = h.at(i);
    while(j < N && h.at(j) != 0) {
      diff = min(diff, h.at(j));
      j++;
    }
    rep2(k, i, j) {
      h.at(k) -= diff;
    }
    result += diff;
    if (h.at(i) == 0) i++;
  }
  cout << result << endl;
}

