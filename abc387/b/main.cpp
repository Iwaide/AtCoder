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

// 99に現れる81個の整数のうちXでないものの総和
int main() {
  int X; cin >> X;
  int ans = 0;
  for(int i = 1; i < 10; i++) {
    for(int j = 1; j < 10; j++) {
      if (i * j != X) {
        ans += i * j;
      }
    }
  }
  cout << ans << endl;
}

