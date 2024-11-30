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

// .@...みたいな感じ
// 最も右にある箱のクッキーを選んで食べる
// Nこの箱それぞれについてD日間経過したあとにその箱にクッキーが入っているかを求めよ
int main() {
  int N, D; cin >> N >> D;
  string S; cin >> S;
  vector<int> cookie;
  rep(i, N) {
    if (S[i] == '@') cookie.push_back(i);
  }
  sort(all(cookie));
  rep(i, D) cookie.pop_back();
  rep(i, N) {
    auto result = find(all(cookie), i);
    if (result == cookie.end()) {
      cout << ".";
    } else {
      cout << "@";
    }
  }
  cout << endl;
}

