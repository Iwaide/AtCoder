#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> csum(2 * N + 1, 0);
  vector<set<int>> mod(M);
  mod[0].insert(0);
  
  rep(i, N * 2) {
    csum[i + 1] = csum[i] + A[i % N];
    mod[csum[i+1] % M].insert(i+1);
  }
  // -------------
  cout << "hoge" << endl;
}

