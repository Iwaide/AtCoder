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

vector<ll> vec;
ll N, K; 
ll solve(ll i) {
  if (i == N) {
    ll res = 0;
    bool can = true;
    // r-lの個数でループさせてみる
    rep(j, N) {
      for(ll l = 1; l <= N - j; l++) {
        ll r = l + j;
        auto min = min_element(vec.begin() + l - 1, vec.begin() + r);
        if (*min * (j + 1) > K) {
          can = false;
          break;
        }
      }
      if (!can) break;
    }
    return can ? 1 : 0;
  }

  ll ans = 0;
  // r-lが0のとき => Aiについて Ai <= K なので AiはすべてK以下である
  // どう考えてもここが遅すぎるしmodできてないし
  for(ll Ai = 0; Ai <= K; Ai++) {
    vec.push_back(Ai);
    ans += solve(i + 1);
    vec.pop_back();
  }
  return ans % 998244353;
}

// 長さNの非負整数列の個数を998244353で割ったあまりを求める
// 1 <= l <= r <= Nを満たす任意の整数の組 (1, 1) (1, 2)...(N, N)みたいなやつ
// min { al, al+1,, ar} * (r - l + 1) <= K
// r-lが0のとき => Aiについて Ai <= K なので AiはすべてK以下である
// r-lが1のとき => min(Ai, Ai+1) * 2 <= K
// r-lが1でNが3のとき 2, , 2
// r-lが2のとき => min(Ai, Ai+1, Ai+2) * 3 <= K
// r-lが2でNが4のとき 2, 0, 0, 2
// ....が成り立つので
int main() {
  cin >> N >> K;
  cout << solve(0) << endl;
}

