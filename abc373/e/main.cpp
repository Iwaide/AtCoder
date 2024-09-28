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

// N種類の品物があり、i種目の重みはw, 価値はvi, どの品物も10^10ある
// 容量Wのバッグに入れる。i種類目の品物をki個選んだときの嬉しさを
// ki * vi - ki ^ 2としたとき、嬉しさの総和が最大になるように品物を選ぶ
// 嬉しさ = ki * vi - ki ^ 2
//       = ki(vi - ki)
int main() {
}

