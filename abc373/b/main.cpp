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

int main() {
  int ans = 0;
  string S; cin >> S;
  map<char, int> M;
  rep(i, S.size()) {
    M[S[i]] = i;
  }
  int start = M['A'];
  for(char c = 'B'; c <= 'Z'; c++) {
    ans += abs(M[c] - start);
    start = M[c];
  }
  cout << ans << endl;
}

