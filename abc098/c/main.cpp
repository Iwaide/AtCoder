#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> E(N + 1, 0), W(N + 1, 0);
  rep(i, S.size()) {
    E.at(i + 1) = E.at(i) + (S.at(i) == 'E' ? 1 : 0);
    W.at(i + 1) = W.at(i) + (S.at(i) == 'W' ? 1 : 0);
  }
  int ans = N;
  rep(i, N) {
    int tmp = W.at(i);
    if (i != N - 1) {
      tmp += E.at(N) - E.at(i + 1);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}

/*
S = EWEEWWEWS....
E, Wをそれぞれ累積和で持って全探索すればいけそう

リーダーi = 2のとき
    E W E E W E W
E:0 1 1 2 3 3 4 4
W:0 0 1 1 1 2 2 3
              L
  
0 ~ i までのWとi + 1 ~ NまでのE
*/