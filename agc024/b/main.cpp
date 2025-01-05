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

// 1以上N以下の整数を並び替えてできる数列Pが与えられる
// 次の操作を繰り返してこの列を昇順に並び替えるとき、操作の回数の最小値を求めよ
// 数列の要素を1つ選び、その要素を列の先頭または末尾のうち好きな方に移動する
// 1. 連続した数値が並んでいるやつが残ればいい
// 2. 数値の位置を表した配列を見ればよい
int main() {
  int N; cin >> N;
  vector<int> A(N), B(200001, -1);
  rep(i, N) {
    cin >> A[i];
    B[A[i]] = i;
  }
  int ans = 0;
  for(int i = 1; i < 200001;) {
    int j = i + 1;
    while(B[j] > B[j - 1] && j < 200001) j++;
    chmax(ans, j - i);
    i = j;
  }
  cout << N - ans << endl;
}

