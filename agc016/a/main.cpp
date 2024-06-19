#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int func(string s, char c) {
//   vector<int> tmp;
//   int ans = 0;
//   rep(i, s.size()) {
//     if (s.at(i) == c) continue;

//     int cnt = s.size() - i;
//     rep2(j, i + 1, s.size()) {
//       if (s.at(j) == c) {
//         cnt = min(cnt, j - i);
//         break;
//       }
//     }
//     ans = max(cnt, ans);
//   }
//   return ans;
// }


int func(string s, char c) {
  set<char> sets;
  int ans = 0;
  while(s.size() > 1) {
    for(char c: s) sets.insert(c);
    if (sets.size() == 1) break;

    sets = {};
    rep(i, s.size() - 1) {
      if (s.at(i) == c || s.at(i + 1) == c) {
        s.at(i) = c;
        sets.insert(c);
      } else {
        sets.insert(s.at(i));
      }
    }
    s.erase(s.size() - 1, 1);
    ans++;
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

