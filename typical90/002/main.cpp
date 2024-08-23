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
  int N; cin >> N;
  if (N % 2 == 1) {
    cout << endl;
    return 0;
  }
  string S;
  rep(i, N / 2) S += "()";
  sort(all(S));
  do {
    string s = S;
    bool valid = true;
    int cnt = 0;
    rep(i, S.size()) {
      if (S[i] == '(') {
        cnt++;
      } else {
        cnt--;
      }
      if (cnt < 0) {
        valid = false;
        break;
      }
    }
    if (valid) {
      cout << S << endl;
    }
  } while(next_permutation(S.begin(), S.end()));
}

