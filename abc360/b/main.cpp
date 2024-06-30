#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S, T;
  cin >> S >> T;
  for(int w = 1; w < S.size(); w++) {
    vector<string> words;
    string Ss = S;
    while(Ss.size() > 0) {
      if (Ss.size() >= w) {
        words.push_back(Ss.substr(0, w));
        Ss.erase(0, w);
      } else {
        words.push_back(Ss);
        Ss.erase(0, Ss.size());
      }
    }
    for(int c = 1; c <= w; c++) {
      string res = "";
      rep(i, words.size()) {
        string word = words.at(i);
        if (word.size() >= c) {
          res += word.at(c - 1);
        }
      }
      if (res == T) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}

