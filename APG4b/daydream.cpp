#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  vector<string> words = {
    "dream",
    "dreamer",
    "erase",
    "eraser"
  };
  reverse(S.begin(), S.end());
  rep(i, 4) reverse(words.at(i).begin(), words.at(i).end());
  bool can = true;
  while(S.size() > 0) {
    bool succeeded = false;
    rep(i, 4) {
      string word = words.at(i);
      if (S.substr(0, word.size()) == word) {
        S.erase(0, word.size());
        succeeded = true;
      }
    }
    if (!succeeded) {
      can = false;
      break; 
    }
  }
  if (can) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
