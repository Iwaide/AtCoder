#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  rep(i, N) cin >> T.at(i);
  sort(T.begin(), T.end());

  int bus_count = 0;
  int passenger = 0;
  int bas_limit = 0;
  rep(i, N) {
    if (T.at(i) <= bas_limit && passenger < C){
      passenger++;
    } else {
      bus_count++;
      passenger = 1;
      bas_limit = T.at(i) + K;
    }
  }
  cout << bus_count << endl;
}

