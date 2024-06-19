#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int func(string s, char c) {
  vector<int> tmp;
  int ans = 0;
  rep(i, s.size()) {
    if (s.at(i) == c) continue;

    int cnt = s.size() - i;
    rep2(j, i + 1, s.size()) {
      if (s.at(j) == c) {
        cnt = min(cnt, j - i);
        break;
      }
    }
    ans = max(cnt, ans);
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  int ans = 100;
  for(char c = 'a'; c <= 'z'; c++) {
    ans = min(ans, func(s, c));
  }
  cout << ans << endl;
}

