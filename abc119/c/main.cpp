#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;

int N, A, B, C;
vector<int> ABC;
vector<int> l;

vector<int> flag;
int solve(int index) {
  if (index == N) {
    int a = 0, b = 0, c = 0, ca = 0, cb = 0, cc = 0;
    rep(i, N) {
      if (flag[i] == 1) a += l[i], ca++;
      if (flag[i] == 2) b += l[i], cb++;
      if (flag[i] == 3) c += l[i], cc++;
    }
    if (ca == 0 || cb == 0 || cc == 0) return INT_MAX;

    int merge = ((ca - 1) + (cb - 1) + (cc - 1)) * 10;
    return merge + abs(A - a) + abs(B - b) + abs(C - c);
  }
  int res = INT_MAX;
  rep(j, 4) {
    flag[index] = j;
    chmin(res, solve(index + 1));
  }
  return res;
}

int main() {
  cin >> N >> A >> B >> C;
  l.resize(N);
  rep(i, N) cin >> l[i];
  flag.resize(N);
  int ans = solve(0);
  cout << ans << endl;
}
