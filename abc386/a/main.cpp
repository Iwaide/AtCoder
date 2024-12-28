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

// 4枚のカードがあり、ABCDと書かれている
// フルハウスにできるか判定せよ
int main() {
  map<int, int> cards;
  rep(i, 4) {
    int n; cin >> n;
    cards[n]++;
  }
  if (cards.size() != 2) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}

