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

// 高橋A枚、青木B枚のクッキー
// 高橋が以下の行動をK回繰り返す
// もし高橋がクッキーを1枚以上持っているなら高橋のを1枚食べる
// そうでなく、青木が1枚以上持っているなら青木のクッキーを1枚食べる
// 高橋青木も持っていないならなにもしない
int main() {
  ll A, B, K;
  cin >> A >> B >> K;
  cout << A - min(A, K) << ' ' << max((B - max(K - min(A, K), 0LL)), 0LL) << endl;
}

