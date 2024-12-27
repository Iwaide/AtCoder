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

// 左から右に並ぶN個の石
// Rのとき赤、Wのとき白
// 1. 石を2個選び、それらを入れ替える
// 2. 石を1個選び、その石の色を変える
// 赤い石の左隣りに白い石がない状態に至るには最小で何回の操作が必要か
// 最終全部RRRRRRWWWWみたいな感じになっていないといけない
// 戦略として、左から見ていってWがあったら右からR取ってきて詰替え？
// もとのところに戻ってきたらbreak
int main() {
  int N; cin >> N;
  vector<char> c(N);
  rep(i, N) cin >> c[i];
  int j = N - 1, ans = 0;
  for(int i = 0; i < N; i++) {
    if (c[i] == 'R') continue;
    while(c[j] == 'W' && i != j) j--;
    if (i == j) break;
    swap(c[i], c[j]);
    ans++;
  }
  cout << ans << endl;
}
