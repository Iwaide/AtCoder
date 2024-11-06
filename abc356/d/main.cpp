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

// 0...Nまでビット単位AND演算(k & M)の結果のうち1をカウントしたのを足した数
// を998244353で割った余りを求めよ
// 規則性を見つける必要がありそう
// N = 4 M = 3(11)のとき
// k = 00 => 0 これは常に0
// k = 01 => 1
// k = 10 => 1
// k = 11 => 2
// k = 100 => 0
// 例えばMの1桁目が1のとき、kに1が来るのは1回おき
// 2桁目が1のとき、kに1が来るのは2回おき
// 3桁目が2のとき、kに1が来るのは4回おき
// 0始まりなので、N + 1を割っていけば答えでそう
ll MOD = 998244353;
int main() {
  ll N, M;
  cin >> N >> M;
  bitset<60> m(M);

  int ans = 0;
  ll span = 2;
  rep(i, 60) {
    // m側が0のとき何がきても0
    if (!m.test(i)) {
      span *= 2;
      continue;
    }

    ll cnt = ((N + 1) / span * (span / 2)) % MOD;
    // ループの余りを考慮しないといけない
    ll modSpan = (N + 1) % span;
    cnt = (cnt + max(0LL, modSpan - span / 2)) % MOD;
    ans = (ans + cnt) % MOD;
    span *= 2;
  }
  cout << ans << endl;
}

