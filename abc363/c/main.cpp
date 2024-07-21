#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K; string S;
  cin >> N >> K >> S;
  int ans;
  sort(S.begin(), S.end());
  do {
    bool ok = true;
    // 範囲内に回文がふくまれてるか
    for(int i = 0; i <= N - K; i++) {
      bool is_palindrome = true;
      // 回分かどうか
      for(int j = 0; j < K; j++) {
        is_palindrome &= S[i + j] == S[i + K - 1 -j];
      }
      ok &= !is_palindrome;
    }
    ans += ok;
  } while(next_permutation(S.begin(), S.end()));
  cout << ans << endl;
}

