#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N;
  vector<string> blues(N);
  rep(i, N) cin >> blues.at(i);
  cin >> M;
  vector<string> reds(M);
  rep(i, M) cin >> reds.at(i);
  int answer = 0;
  rep(i, N) {
    string S = blues.at(i);
    int point = 0;
    rep(j, N) if (blues.at(j) == S) point++;
    rep(j, M) if (reds.at(j) == S) point--;
    answer = max(answer, point);
  }
  cout << answer << endl;
}
