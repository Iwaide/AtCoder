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

int main() {
  int N; cin >> N;
  vector<vector<vector<int>>> F(N, vector<vector<int>>(5, vector<int>(2)));
  rep(i, N) {
    rep(j, 5) {
      rep(k, 2) {
        cin >> F[i][j][k];
      }
    }
  }
  vector<vector<int>> P(N, vector<int>(11));
  rep(i, N) {
    rep(j, 11) {
      cin >> P[i][j];
    }
  }

  int ans = INT_MIN;
  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  rep2(i, 1, (1 << 10)) {
    bitset<10> b(i);
    int tmp = 0;
    // 店iごとに利益が決まる
    rep(l, N) {
      // 営業時間被りの個数
      int cnt = 0;
      rep(j, 5) {
        rep(k, 2) {
          // 指定の曜日に営業しているかどうか
          if (b.test(2 * j + k)) {
            if (F[l][j][k]) cnt++;
          }
        }
      }
      tmp += P[l][cnt];
    }
    chmax(ans, tmp);
  }
  cout << ans << endl;
}

