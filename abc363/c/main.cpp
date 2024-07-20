#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<char> S(N);
  rep(i, N) cin >> S[i];
  set<string> ans;
  sort(S.begin(), S.end());
  do {
    bool is_contain = false;
    // 範囲内に回文がふくまれてるか
    for(int i = 0; i <= S.size() - K; i++) {
      bool is_palindrome = true;
      // 回分かどうか
      for(int j = 0; j < K / 2; j++) {
        char f = S.at(i + j);
        char l = S.at(i + K - 1 - j);
        // 回文じゃなかったらbreak;
        if (f != l) {
          is_palindrome = false;
          break;
        }
      }
      if (is_palindrome) {
        is_contain = true;
        break;
      }
    }
    if (!is_contain) {
      string s(S.begin(), S.end());
      ans.insert(s);
    }
  } while(next_permutation(S.begin(), S.end()));
  cout << ans.size() << endl;
}

