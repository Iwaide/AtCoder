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

// N種類の元素がある
// i >= j のとき Ai,jに、 i < jのとき Aj,iに変化する
int main() {
  int N; cin >> N;
  vector<vector<int>> A(N + 1, vector<int>(N + 1));
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= i; j++) {
      cin >> A[i][j];
    }
  }
  int ans = 1;
  for(int i = 1; i <= N; i++) {
    if (ans >= i) {
      ans = A[ans][i];
    } else {
      ans = A[i][ans];
    }
  }
  cout << ans << endl;
}

