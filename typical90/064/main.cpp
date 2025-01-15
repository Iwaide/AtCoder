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

// 日本はN個の区画に分けられており、西からi番目の標高はAi
// Q回の地殻変動が起きる、Li,Li+1...,Riの標高がViだけ変化する 
// 区画1からNに行く不便さは次のように定義される
// 区画iの標高をEiとするとき、|E1- E2| + |E2 - E3| ...|EN-1 - EN|
// 各地殻変動後の不便さをそれぞれ求めよ
// 差分取っておく
int main() {
  int N, Q; cin >> N >> Q;
  vector<ll> A(N), diff(N - 1, 0);
  ll ans = 0;
  rep(i, N) {
    cin >> A[i];
    if (i > 0){
      diff[i - 1] = A[i] - A[i - 1];
      ans += abs(diff[i - 1]);
    }
  }
  rep(i, Q) {
    int Li, Ri, Vi;
    cin >> Li >> Ri >> Vi;
    Li--, Ri--;
    int Lindex = Li - 1, Rindex = Ri;
    if (Lindex >= 0) {
      ans -= abs(diff[Lindex]);
      diff[Lindex] += Vi;
      ans += abs(diff[Lindex]);
    }
    if (Rindex < N - 1) {
      ans -= abs(diff[Rindex]);
      diff[Rindex] -= Vi;
      ans += abs(diff[Rindex]);
    }
    cout << ans << endl;
  }
}

