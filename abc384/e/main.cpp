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

// 縦H横Wのマス目
// Sijのスライムがおり、マス(P, Q)にいるスライムが高橋くん
// 隣接するスライムのうち、強さが1/X未満のものを選んで吸収、
// 高橋くんの強さは吸収したスライムの強さだけ増加
using t = tuple<ll, ll, ll>;
vector<pair<int, int>> dxy = {
  { -1, 0 },
  { 0, 1 },
  { 1, 0 },
  { 0, -1 }
};

int main() {
  ll H, W, X, P, Q;
  cin >> H >> W >> X >> P >> Q;
  P--, Q--;
  vector<vector<ll>> Grid(H, vector<ll>(W, 0));
  rep(i, H) rep(j, W) cin >> Grid[i][j];

  ll S = 0;
  priority_queue<t, vector<t>, greater<t>> q;
  q.push({ Grid[P][Q], P, Q });

  vector<vector<bool>> visited(H, vector<bool>(W, false));
  while(!q.empty()) {
    auto qi = q.top(); q.pop();
    ll v = get<0>(qi), x = get<1>(qi), y = get<2>(qi);
    if (visited[x][y]) continue;
    visited[x][y] = true;
    if (x == P && y == Q) {
      S += v;
    } else if (((double)S / (double) X) > (double) v) {
      S += v;
    } else {
      continue;
    }
    rep(i, 4) {
      ll dx = x + dxy[i].first, dy = y + dxy[i].second;
      if (dx >= 0 && dx < H && dy >= 0 && dy < W) {
        if (!visited[dx][dy]) {
          q.push({ Grid[dx][dy], dx, dy });
        }
      }
    }
  }
  cout << S << endl;
}

