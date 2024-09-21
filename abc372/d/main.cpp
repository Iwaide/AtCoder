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

// 1, 2, 3, 4, 5 みたいな数列が並び替えられている、と考えるのが良さそう?
// 2, 1, 3, 4, 5みたいになってる
// i = 1 つまり 2から見ていって、2, 1の間に1より高いのがないか
// 2, 3より高いのがないか…を見ていく
// なんか普通にやっても良さそうな気するけどTLEすんのかな？
// N^2ぐらいありそうだな普通にやると
// 区間のmax取る、みたいな話だから累積なんとか、みたいなの使えそうだけど
// 区間のMAXって
int main() {
  int N; cin >> N;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  rep(i, N) {
    int max = 0;
    int ans = 0;
    int j = i + 1;
    while(j < N) {
      if (max < H[j]) {
        ans++;
      }
      chmax(max, H[j]);
      j++;
    }
    cout << ans;
    if (i != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}
