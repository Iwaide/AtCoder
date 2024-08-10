#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  int maxLength = 0;
  rep(i, N) {
    cin >> S[i];
    if(maxLength > S[i].size()) {
      S[i].resize(maxLength, '*');
    }
    chmax(maxLength, (int) S[i].size());
  }


  rep(i, maxLength) {
    for(int j = N - 1; j >= 0; j--) {
      if (i < S[j].size()) {
        cout << S[j][i];
      }
    }
    cout << endl;
  }
}

