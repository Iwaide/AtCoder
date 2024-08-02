#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// 前後が同じ文字のとき
// 'issii' => 前方のみ1個、後方のみ1個、前方+後方 K - 1
// 前後が同じ文字でないとき => そのまま計算
// 'cdddt' => 1 'cdedt'
// 'cddddt' => 2 'cdedet'
// 全部同じ文字のとき
// 'iiiii' => K掛けて2で割る(切り捨て)
int main() {
  string S; long long K;
  cin >> S >> K;
  vector<pair<char, int>> vec;
  for(int i = 0; i < S.size();) {
    char c = S[i];
    int j = i + 1;
    while(c == S[j]) j++;
    vec.push_back(make_pair(c, j - i));
    i = j;
  }
  // 全部同じ文字のとき
  if(vec.size() == 1) {
    auto pair = vec[0];
    long long ans = (1LL * pair.second * K) / 2;
    cout << ans << endl;
    return 0;
  }
  auto first = vec[0]; auto last = vec[vec.size() - 1];
  // 最初の文字と後ろの文字が同じとき
  if (first.first == last.first && K > 1) {
    long long ans = 0;
    ans += first.second / 2;
    ans += last.second / 2;
    ans += 1LL * (first.second + last.second) / 2 * (K - 1);
    long long tmp = 0;
    for(int i = 1; i < vec.size() - 1; i++) {
      tmp += vec[i].second / 2;
    }
    ans += tmp * K;
    cout << ans << endl;
  } else {
    long long tmp = 0;
    rep(i, vec.size()) tmp += vec[i].second / 2;
    cout << tmp * K << endl;
  }
}
