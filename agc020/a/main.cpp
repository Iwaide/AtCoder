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

// N個のマス上でゲームを行う
// アリスのコマがマスA, ボリスのコマがB
// アリス先手、自分の駒を現在のマスXから左右どちらかに動かす
// コマを動かせなくなった人が負け
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  A--, B--;
  if (abs(B - A) % 2) {
    cout << "Borys" << endl;
  } else {
    cout << "Alice" << endl;
  }
}

