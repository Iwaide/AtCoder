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

// 英小文字のみからなるS, Tがある
// S, Tが等しいなら0を、そうでないなら異なっている文字のうち戦闘のものが何文字目か
int main() {
  string S, T;
  cin >> S >> T;
  int N = max(S.size(), T.size());
  bool can = true;
  rep(i, N) {
    // 文字足りてないときはその時点の出力して終わり
    if (S.size() < i || T.size() < i) {
      cout << (i + 1) << endl;
      can = false;
      break;
    }
    if (S[i] != T[i]) {
      cout << (i + 1) << endl;
      can = false;
      break;
    }
  }
  if (can) {
    cout << 0 << endl;
  }
}

