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
// H行W列のマス目
// aij枚のコインが置かれている
// まだ選んだことのないマスの内1枚以上のコインが置かれているマスを1つ選び、
// そのマスに置かれているコインのうち1枚を上下左右に隣接するいずれかのマスに移動する
// 偶数枚のコインが置かれたマスの数を最大化せよ
// 一筆書きしていって石を移動させる
int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> Grid(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> Grid[i][j];

  // 石を保持しているか
  bool stacked = false;
  vector<vector<pair<int, int>>> routes;
  vector<pair<int, int>> route;
  rep(i, H) {
    if (i % 2 == 0) {
      for(int j = 0; j < W; j++) {
        if (stacked) {
          // 奇数のとき、石をおいて終わり
          if (Grid[i][j] % 2) {
            route.push_back({ i, j });
            stacked = false;
            routes.push_back(route);
            route = vector<pair<int, int>>();
          // 偶数のとき移動継続
          } else {
            route.push_back({i , j});
          }
        } else {
          // 偶数のときはなにもしない
          if (Grid[i][j] % 2) {
            route.push_back({i , j});
            stacked = true;
          }
        }
      }
    } else {
      for(int j = W - 1; j >= 0; j--) {
        if (stacked) {
          // 奇数のとき、石をおいて終わり
          if (Grid[i][j] % 2) {
            route.push_back({ i, j });
            stacked = false;
            routes.push_back(route);
            route = vector<pair<int, int>>();
          // 偶数のとき移動継続
          } else {
            route.push_back({i , j});
          }
        } else {
          // 偶数のときはなにもしない
          if (Grid[i][j] % 2) {
            route.push_back({i , j});
            stacked = true;
          }
        }
      }
    }
  }
  int ans_cnt = 0;
  for(auto route : routes) {
    ans_cnt += route.size() - 1;
  }
  cout << ans_cnt << endl;
  for(auto route : routes) {
    for(int i = 0; i < route.size() - 1; i++) {
      cout << route[i].first + 1 << ' ' << route[i].second + 1 << ' ';
      cout << route[i + 1].first + 1<< ' ' << route[i + 1].second + 1 << endl;
    }
  }
}

