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

// 整数aiが書かれたN個のレンガ
// N-1個以下の任意のレンガを選んで砕くことができる
// 残ったK個のレンガのうち、任意の整数iについて残っているレンガの中で
// 左からi番目のものに書かれた整数がiであるようにしろ
// 砕かなければならないレンガの個数は？
// もしどう砕いてもだめなら-1を出力しろ
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int counter = 1, ans = 0;
  rep(i, N) {
    if (counter == A[i]) {
      counter++;
      continue;
    } else {
      ans++;
    }
  }
  cout << (ans == N ? -1 : ans) << endl;
}

