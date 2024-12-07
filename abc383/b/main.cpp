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

// H行W列のマスがある
// Sijが#のとき机、.のとき床
// 床から2マス選んで加湿器を設置する
// マンハッタン距離がD以下のとき加湿される
// マンハッタン距離は |i - i'| + |j - j'|で表される
// 加湿器が置かれた床のますは必ず加湿されている
// 加湿される床のマスの個数として考えられる最大値を求めよ
int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<vector<char>> O(H, vector<char>(W));
  vector<pair<int, int>> F;
  rep(i, H) {
    rep(j, W) {
      cin >> O[i][j];
      if (O[i][j] == '.') {
        F.push_back({ i, j });
      }
    }
  }

  int ans = 0;
  // 床の組み合わせを全部試す
  for(int i = 0; i < F.size() - 1; i++) {
    for(int j = i + 1; j < F.size(); j++) {
      auto h1 = F[i], h2 = F[j];
      auto OCopy = O;
      int cnt = 2;
      OCopy[h1.first][h1.second] = '!';
      OCopy[h2.first][h2.second] = '!';
      rep(i, H) {
        rep(j, W) {
          if (abs(h1.first - i) + abs(h1.second - j) <= D ||
              abs(h2.first - i) + abs(h2.second - j) <= D) {
                if (OCopy[i][j] == '.') cnt++;
              }
        }
      }
      chmax(ans, cnt);
    }
  }
  cout << ans << endl;
}

