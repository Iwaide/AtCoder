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

// 10^100個の植木鉢がある
// Q個のクエリを処理せよ
// 1, 植物が植えられていない植木鉢を1個用意し、その植木鉢に植物を植える。高さは0
// 2 T: T日待つ、このとき植えてあるすべての植物の高さがT増加する
// 3 H: 高さがH以上の植物をすべて収穫し、収穫した植物の数を出力する
int main() {
  int Q; cin >> Q;
  // mapで植えられた日の累積和つけていけば良さそう？
  map<ll, int> m;
  ll current = 0;
  ll last = -1;
  m[-1] = 0;
  rep(i, Q) {
    int q; cin >> q;
    if (q == 1) {
      m[current] += 1;
    } else if (q == 2) {
      ll T; cin >> T;
      m[current + T] = m[current];
      current += T;
    } else if (q == 3) {
      ll H; cin >> H;
      // last ~ current - Hの区間を取れば良い？
      auto k = m.upper_bound(current - H);
      if (k != m.begin()) {
        k--;
        cout << k->second - m[last] << endl;
        last = k->first;
      } else {
        cout << 0 << endl;
      }
    }
  }
}

