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

// H行W列のマス
// #のとき通行不可能.のとき家が建ってない、@のとき通行可能
// (X, Y)にサンタがいる
// |T|とするとき
// U -> (x - 1, y)が通行可能な時そこに移動
// DLR同様
// 行動により通過、到達した家の数を求めよ
map<char, pair<int, int>> dxy = {
  { 'U', { -1, 0 }},
  { 'D', { 1, 0 }},
  { 'L', { 0, -1 }},
  { 'R', { 0, 1 }}
};

int main() {
  int H, W, X, Y;
  cin >> H >> W >> X >> Y;
  X--, Y--;
  vector<vector<char>> Grid(H, vector<char>(W));
  set<pair<int, int>> house;
  rep(i, H) rep(j, W) {
    cin >> Grid[i][j];
    if (Grid[i][j] == '@') house.insert({ i, j });
  }
  int house_cnt = house.size();

  string T;
  cin >> T;
  int x = X, y = Y;
  rep(i, T.size()) {
    char Ti = T[i];
    auto dxyi = dxy[Ti];
    int dx = x + dxyi.first, dy = y + dxyi.second;
    if (dx >= 0 && dx < H && dy >= 0 && dy < W) {
      if (Grid[dx][dy] == '#') continue;
      if (Grid[dx][dy] == '@') {
        house.erase({ dx, dy });
      }
      x = dx, y = dy;
    }
  }
  cout << x + 1 << " " << y + 1 << " " << house_cnt - house.size() << endl;
}

