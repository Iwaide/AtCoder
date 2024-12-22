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
// 長さNの数列が飾られている
// すべてのiに対してaiの値を2で割るか、3倍するのどちらかを行う
// すべてを3倍することはできず、操作後のaiは整数でなければいけない
// どれか1個を2で割っていく、つまり2で割れる数を足した数が答え
int main() {
  int N;
  cin >> N;
  vector<ll> a(N, 0);
  rep(i, N) cin >> a[i];
  ll ans = 0;
  rep(i, N) {
    ll ai = a[i];
    while(ai % 2 == 0) {
      ans++;
      ai /= 2;
    }
  }
  cout << ans << endl;
}

