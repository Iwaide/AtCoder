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

// 1...Nを並び替えた長さNの数列
// 連続したK個の要素を選ぶ、その後選んだ要素それぞれの値を選んだ要素の中の最小値で置き換える
// 数列の要素をすべて等しくするために必要な回数の最小値
// 最終全部1になるはず
// 1の出現位置の前後の数で回数が決まるはず
// K個選ぶ時1個は1を含めておかないといけないから、K-1個ずつ処理できる
// 切り上げで割り算
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N, 0);
  rep(i, N) {
    int Ai; cin >> Ai;
    if (Ai == 1) {
      int ans = ((i + K - 1 - 1) / (K - 1)) + ((N - i - 1) + K - 1 - 1) / (K - 1);
      cout << ans << endl;
      return 0;
    }
  }
}

