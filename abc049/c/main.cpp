#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  vector<string> words = {
    "dream",
    "dreamer",
    "erase",
    "eraser"
  };
  rep(i, 4) reverse(words.at(i).begin(), words.at(i).end());


  while(S.size() > 0) {
    bool can = false;
    rep(i, 4) {
      string word = words.at(i);
      if (S.substr(0, word.size()) == word) {
        S.erase(0, word.size());
        can = true;
      }
    }
    if (!can) {
      cout << "NO" <<endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}

