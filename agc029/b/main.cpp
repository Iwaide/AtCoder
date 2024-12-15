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

// 正整数が書かれたボールをN個もっている
// N個のボールからいくつかのペアを作って数の我が2べきとなるようにしたい
int main() {
  int N; cin >> N;
  map<ll, set<int>> A;
  set<ll, greater<ll>> B;
  rep(i, N) {
    ll Ai; cin >> Ai;
    A[Ai].insert(i);
    B.insert(Ai);
  }
  // 2のべき乗の配列作る
  vector<ll> pow_2(33, 0);
  pow_2[0] = 1;
  rep(i, 32) pow_2[i + 1] = pow_2[i] * 2;

  vector<bool> paired(N, false);
  int ans = 0;
  for(auto b: B) {
    auto a = A[b];
    for(auto idx : a) {
      if (paired[idx]) continue;
      bool is_pair = false;
      auto init_j = lower_bound(all(pow_2), b * 2) - pow_2.begin();
      for(int j = init_j; pow_2[j] > b; j--) {
        ll p = pow_2[j];
        for(auto h : A[p - b]) {
          if (idx == h) continue;
          if (paired[h]) continue;
          paired[idx] = true;
          paired[h] = true;
          is_pair = true;
          ans++;
          A[p - b].erase(h);
          A[p - b].erase(idx);
          break;
        }
        if (is_pair) break;
      }
    }
  }
  cout << ans << endl;
}

