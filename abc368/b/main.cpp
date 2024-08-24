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

// Nの生成数列A Aを要素の降順に並び替えるそれからA1, A2を1減らす
int main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int ans = 0;
  int cnt = N;
  while(cnt > 1) {
    ans++;
    sort(all(A), greater<int>());
    rep(i, 2) {
      if (A[i] > 0) {
        A[i] -= 1;
        if (A[i] <= 0) {
          cnt--;
        }
      }
    }
  }
  cout << ans << endl;
}