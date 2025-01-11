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

// N個の餅が小さい方から順に並んでいる.i番目の餅の大きさはAi
// 2つの餅A, Bの大きさをa,bとしたとき、aがbの半分以下のとき鏡餅を1つ作れる
// N個の餅から2つの餅を選び、一方をもう一方に載せることで鏡餅を1つ作る
// 何種類の鏡餅を作れるか、求めよ
int main() {
  int N; cin >> N;
  map<int, int> A;
  rep(i, N) {
    int Ai; cin >> Ai;
    A[Ai]++;
  }
  // 大きさをキーにした累積和を作っておく？
  map<int, int> cumulative;
  int before = 0;
  for(auto a : A) {
    cumulative[a.first] = cumulative[before] + a.second;
    before = a.first;
  }
  ll ans = 0;
  for(auto a : A) {
    int target = a.first / 2;
    auto key = cumulative.upper_bound(target);
    if (key != cumulative.begin()) {
      key--;
      ans += a.second * key->second;
    }
  }
  cout << ans << endl;
}

