#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<long long> H(N);
  rep(i, N) cin >> H.at(i);
  
  int result = 0;
  for(int i = 0; i < N;) {
    int j = i + 1;
    while(j < N && H.at(j - 1) >= H.at(j)) {
      j++;
    }
    result = max(result, j - i - 1);
    i = j;
  }
  cout << result << endl;
}

