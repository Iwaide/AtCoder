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

int N;
string S;

// 1 2 3
int main() {
  cin >> S;
  // +を入れられる箇所
  N = S.size() - 1;
  ll ans = 0;
  rep(i, 1 << N) {
    bitset<9> b(i);
    ll tmp = 0;
    ll sum = 0;
    rep(j, N + 1) {
      if (j <= N) sum = sum * 10 + stoll(S.substr(j, 1));
      if (j == N || b.test(j)) {
        tmp += sum;
        sum = 0;
      }
    }
    ans += tmp;
  }
  cout << ans << endl;
}

