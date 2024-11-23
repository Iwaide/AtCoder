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

// |T| は奇数
// 1文字目から　|T| + 1 / 2 - 1文字目までが1
// |T| + 1 / 2 文字目が/
// |T| + 1 / 2 + 1文字目から|T|文字目までが2
int main() {
  int N; cin >> N;
  string S; cin >> S;
  bool can = true;
  if (N % 2 == 0) {
    cout << "No" << endl;
    return 0;
  }

  rep2(i, 1, N + 1) {
    if (i <= (N + 1) / 2 - 1) {
      if (S[i - 1] != '1') can = false;
    } else if (i == ((N + 1) / 2)) {
      if (S[i - 1] != '/') can = false;
    } else {
      if (S[i - 1] != '2') can = false;
    }
  }
  cout << (can ? "Yes" : "No") << endl;
}

