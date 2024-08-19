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

int count_cell(vector<vector<char>> &grid) {
  int res = 0;
  for(auto row: grid) {
    for(char c: row) {
      if (c == '#') res++;
    }
  }
  return res;
}

int main() {
  int H, W, K;
  cin >> H >> W >> K;

  vector<vector<char>> C(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> C[i][j];
    }
  }

  int ans = 0;
  rep(i, (1 << H)) {
    bitset<6> h(i);
    rep(j, (1 << W)) {
      bitset<6> w(j);
      vector<vector<char>> copy = C;
      rep(x, H) {
        if(h.test(x)) {
          rep(y, W) {
            copy[x][y] = 'R';
          }
        }
      }
      rep(y, W) {
        if(w.test(y)) {
          rep(x, H) {
            copy[x][y] = 'R';
          }
        }
      }
      if (count_cell(copy) == K) ans++;
    }
  }
  cout << ans << endl;
}

