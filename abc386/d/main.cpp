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

// N行N列のグリッドがある以下の条件を満たすように各マスを黒か白に塗り分ける
// すべての行について以下の条件が成り立つ
// ある整数iが存在して、その行の左からiこのますは黒、それ以外は白で塗られている
// すべての列について以下の条件が成り立つ
// ある整数iが存在して、その列の上からi個のますは黒、それ以外は白で塗られている
// M個のますがすでに塗られている
// まだ塗られていない残りのマスの色を決めて条件を満たせるか判定せよ
// Mが2 * 10^5だからMベースで考える必要が有りそう
// 塗れない時を考える
// 各x, yについて黒マスより先に白マスがあってはいけない
int main() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, char>> xyc;
  rep(i, M) {
    int x, y; char c;
    cin >> x >> y >> c;
    xyc.push_back({ x, y, c});
  }
  sort(all(xyc));
  string ans = "Yes";
  int min_y = INT_MAX;
  for(auto t : xyc) {
    if (get<2>(t) == 'W') {
      chmin(min_y, get<1>(t));
    } else {
      if (get<1>(t) >= min_y) {
        ans = "No";
      }
    }
  }
  cout << ans << endl;
}
