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

// 同時にいくつの鏡餅を作れるか
int main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int ok = (N / 2) + 1, ng = 0;
  while(ok - ng > 1) {
    int K = (ok + ng) / 2;
    bool can = true;
    rep(i, K) {
      if (A[i] * 2 > (A[N - K + i])) {
        can = false;
        break;
      }
    }
    if (can) {
      ng = K;
    } else {
      ok = K;
    }
  }
  cout << ok - 1 << endl;
}
