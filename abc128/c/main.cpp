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
  int N, M; cin >> N >> M;
  vector<int> k(M);
  vector<vector<int>> S;
  vector<int> p(M);
  rep(i, M) {
    cin >> k[i];
    vector<int> s(k[i]);
    rep(j, k[i]) {
      cin >> s[j];
      s[j]--;
    }
    S.push_back(s);
  }
  rep(i, M) {
    cin >> p[i];
  }

  int ans = 0;
  rep(i, 1 << N) {
    bitset<10> b(i);
    bool can = true;
    rep(j, M) {
      auto s = S[j];
      int on = 0;
      for(auto si: s) {
        if(b.test(si)) on++;
      }
      if (on % 2 != p[j]) {
        can = false;
        break;
      }
    }
    if (can) ans++;
  }

  cout << ans << endl;
}

