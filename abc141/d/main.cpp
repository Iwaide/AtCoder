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

// N個の品物を1個ずつ買う
// i番目の品物の値段はAi円
// M枚の割引券がある
// X円の品物を買う際にY枚の割引券を使うと X / 2 ^ Y円で買える
// 最小で何円あればすべての品物を買うことができるか
// 高いやつにたくさん割引券を使ったほうが得そうだけど
int main() {
  int N, M;
  cin >> N >> M;
  priority_queue<int> A;
  rep(i, N) {
    int Ai; cin >> Ai;
    A.push(Ai);
  }

  rep(i, M) {
    int largeA = A.top(); A.pop();
    A.push(largeA / 2);
  }
  ll ans = 0;
  while(!A.empty()) {
    ans += A.top(); A.pop();
  }
  cout << ans << endl;
}
