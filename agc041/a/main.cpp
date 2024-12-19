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

// 2N人の卓球選手が1からNまでの番号がついたN台の卓で練習を行う
// 練習は複数のラウンドからなる
// 卓Xで勝利した選手は次X-1で試合を行う、ただし1で勝利した選手は1にとどまる
// 敗北するとX+1で試合を行う
// 2人の選手は友達同士で、A, Bで行う、2人同士で試合を行えるまでに最小で何ラウンド必要か
int main() {
  // abs(B - A)が偶数のときは2で割った結果
  // 奇数のときは
  // どっちか片方が端に近い方に行ってそこから偶数になるまで待ってから戻る 
  // 間自体は変わらないから
  ll N, A, B;
  cin >> N >> A >> B;
  if ((B - A) % 2) {
    ll dis = min(A - 1, N - B);
    ll bet = B - A - 1;
    cout << dis + 1 + (bet / 2) << endl;
  } else {
    // 偶数のとき
    cout << abs(B - A) / 2 << endl;
  }
}

