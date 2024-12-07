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

// AtCoder社のオフィスには加湿器が1つある。
// 現在時刻は0
// N回水を足す。時刻TiにViリットル足す
// 1単位時間につき水が1リットル減る
// 時刻TNに水を追加し終えた時加湿器に残っている水の量を求めよ
int main() {
  int N; cin >> N;
  int W = 0, current = 0;
  rep(i, N) {
    int Ti, Vi; cin >> Ti >> Vi;
    W = max(0, W - (Ti - current));
    W += Vi;
    current = Ti;
  }
  cout << W << endl;
}

