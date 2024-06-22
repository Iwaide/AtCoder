#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  long long cnt = 0;
  long long pair_cnt = K / 2;
  long long last_s = S.size() - 1;
  rep(i, (S.size() - K + 1)) {
    long long tmp_cnt = 0;
    rep(j, pair_cnt) {
      char first = S.at(i + j);
      char last = S.at(last_s - j - i);
      if (first == '?' && last == '?') {
        //
        tmp_cnt += 4;
        continue;
      }
      if (first == '?' || last == '?') {
        tmp_cnt += 1;
        continue;
      }
      if (first != last) {
        tmp_cnt = 0;
        break;
      }
    }
    if (K % 2 == 1 && S.at((i + pair_cnt) == '?')) {
      //
      tmp_cnt *= 2;
    }
    cnt += tmp_cnt;
  }

  long long q_cnt = 0;
  rep(i, S.size()) if (S.at(i) == '?') q_cnt++;
  if (q_cnt == 0) {
    cout << 0 << endl;
    return 0;
  }

  long long total = 1;
  rep(i, q_cnt) {
    total = (total % 998244353LL) * 2;
  }
  long long ans = (total - cnt) % 998244353LL;
  cout << ans << endl;
}

