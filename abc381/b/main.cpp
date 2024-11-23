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

// |T|は偶数
// 1 <= i <= |T| / 2を満たすiについてTの(2i - 1)文字目と2i文字目は等しい
// 各文字はTにちょうど0個または2個現れる
int main() {
  string S;
  cin >> S;
  if (S.size() % 2) {
    cout << "No" << endl;
    return 0;
  }
  rep2(i, 1, S.size() / 2 + 1) {
    if (S[2 * i - 1 - 1] != S[2 * i - 1]) {
      cout << "No" << endl;
      return 0;
    }
  }
  map<char, int> m;
  rep(i, S.size()) {
    m[S[i]] += 1;
  }
  for(auto p : m) {
    if (p.second != 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

