#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()
template<typename T>
void print_vector(vector<T> &vec) {
  rep(i, vec.size()) {
    if (i != vec.size() - 1) {
      cout << vec[i] << " ";
    } else {
      cout << vec[i] << endl;
    }
  }
}

// 01からなる長さNの文字列Sと正整数Kが与えられる
// lからrについて反転させる
// 逆立ちした人を最大で何人連続で並ばせられるか
// 1, 0のランレングス圧縮を作る(1, 1, 3, 1, 1)
// 0を反転させるということは0を飛ばした累積和の区間を求めれば良いということになる
int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  // ランレングス圧縮
  vector<int> vec, cumsum;
  if (S[0] != '1') vec.push_back(0);
  for(int i = 0; i < N;) {
    int j = i + 1;
    while(S[i] == S[j] && j < N) j++;
    vec.push_back(j - i);
    i = j;
  }
  if (S[N - 1] == '0') vec.push_back(0);

  cumsum.resize(vec.size() + 1);
  cumsum[0] = 0;
  for(int i = 0; i < vec.size(); i++) {
    cumsum[i + 1] = cumsum[i] + vec[i];
  }
  int ans = 0, distance = min(2 * K + 1, (int) vec.size());
  for(int i = 0; i < cumsum.size() - distance; i += 2) {
    chmax(ans, cumsum[i + distance] - cumsum[i]);
  }
  cout << ans << endl;
}

