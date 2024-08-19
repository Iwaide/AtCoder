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

int N, M, Q;
vector<tuple<int, int, int, int>> F(Q);
ll rec(vector<int> &A) {
  if (A.size() == N) {
    ll tmp = 0;
    rep(i, Q) {
      auto f = F[i];
      if (A[get<1>(f)] - A[get<0>(f)] == get<2>(f)) {
        tmp += get<3>(f);
      }
    }
    return tmp;
  }
  ll ans = 0;
  int min = 1;
  if (A.size() > 0) {
    min = A.back();
  }
  for(int j = min; j <= M; j++) {
    A.push_back(j);
    chmax(ans, rec(A));
    A.pop_back();
  }
  return ans;
}

// 正の整数N, M, Qと 整数の組(ai, bi, ci, di)がQ組与えられる
// Aは長さNの正整数列
// A: 1 <= A1 <= A2 <= A3 <= ... M
// Abi - Aai = ci を満たすようなiについてのdiの総和
// forの初期化条件間違えてたけど、解法としては合ってたっぽい
// 再帰関数に配列を渡すのに慣れない
int main() {
  cin >> N >> M >> Q;
  F.resize(Q);
  rep(i, Q) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    b--; a--;
    F[i] = make_tuple(a, b, c, d);
  }
  vector<int> A;
  ll ans = rec(A);
  cout << ans << endl;
}

