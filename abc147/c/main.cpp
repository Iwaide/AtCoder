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
  int N;
  cin >> N;
  vector<int> A(N);
  vector<vector<pair<int, int>>> xys(N);
  rep(i, N) {
    cin >> A[i];
    rep(j, A[i]) {
      int x, y; cin >> x >> y;
      xys[i].push_back(make_pair(x, y));
    }
  }
  int ans = 0;
  rep(i, 1 << N) {
    bitset<15> b(i);
    // 制約が成立するか
    bool tf = true;
    // 正直者の人数
    int truths = 0;
    rep(j, N) {
      // j番目の人が正直者かどうか
      if (b.test(j)) {
        truths++;
        auto xy = xys[j];
        bool can = true;
        for(auto pair: xy) {
          if (b.test(--pair.first) != pair.second) {
            can = false;
            break;
          }
        }
        if (!can) {
          tf = false;
          break;
        }
      }
    }
    if (tf) chmax(ans, truths);
  }
  cout << ans << endl;
}

