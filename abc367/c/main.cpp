#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
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

int N, K;
vector<int> seq(8);
vector<int> R(8);
void solve(int lv) {
  if (lv == N) {
    int sum = 0;
    rep(i, N) sum += seq[i];
    if (sum % K == 0) {
      rep(i, N) {
        if (i) cout << " ";
        cout << seq[i];
      }
      cout << endl;
    }
  }
  rep2(i, 1, R[lv] + 1) {
    seq[lv] = i;
    solve(lv+1);
  }
}

int main() {
  cin >> N >> K;
  rep(i, N) cin >> R[i];
  solve(0);
  return 0;
}
