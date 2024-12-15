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

// 周期Nをもつ無限数列の先頭N項A1, A2..ANが与えられる
// 個の数列のから出ない連続する部分列の内、和がSとなるものが存在するか判定せよ
int main() {
  ll N, S; cin >> N >> S;
  ll loop = 0;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
    loop += A[i];
  }
  ll rest = (S - (S / loop) * loop);
  // スタート位置をlower_boundで決めて尺取り？
  vector<ll> cum(2 * N, 0);
  cum.push_back(0);
  rep(i, 2 * N) {
    cum[i + 1] = cum[i] + A[i % N];
  }

  for(int l = 0; l < 2 * N; l++) {
    ll li = cum[l];
    if (binary_search(all(cum), rest + li)) {
      cout << "Yes" << endl;
      return 0;
    } 
  }
  cout << "No" << endl;
}

