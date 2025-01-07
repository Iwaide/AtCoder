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
ll int_pow(ll a, ll b) {
  ll res = 1;
  rep(_, b) res *= a;
  return res;
}

// Rを4565と考える
ll count_snake_numbers(ll R) {
  string s = to_string(R);
  vector<int> digit;
  rep(i, s.size()) digit.push_back(s[i] - '0');

  ll ans = 0;
  // 1. R自体が蛇数か、そうでないか
  // 4565は蛇数ではない
  int d1 = digit[0];
  bool is_snake = true;
  for(int i = 1; i <= digit.size(); i++) {
    if (i == digit.size()) {
      ans++; break;
    }
    ans += int_pow(d1, digit.size() - (i + 1)) * min(d1, digit[i]);
    if (digit[i] >= d1) break;
  }

  for(int i = 0; i < digit.size(); i++) {
    int mx = (i ? 9 : digit[0] - 1);
    for(int j = 1; j <= mx; j++) {
      ans += int_pow(j, digit.size() - 1 - i);
    }
  }
  return ans;
}

// Rがn桁の数であり、上からi桁目の数がdiであるとする
// R以下の任意の正整数xは以下のいずれかちょうど1つの条件を満たす
// 1. x = Rである
// 2. xはn桁の数であり、上からk(1 <= k <= n -1)桁目までの数がRと一致し、上からk+1桁目の数がdk+1より小さい
// 3. xはn桁の数であり、上から1桁目の数がd1より小さい
// 4. xはk(1 <= k <= n -1)桁の数である
// それぞれが蛇数であるものの個数を計算する
// 1. Rが蛇数ならば1個、そうでないなら0個
// 2. あるi(2 <= i <= k)について、d1 <= diならば0個、そうでないならk + 1桁目の数がd1未満かつdk+1未満で
// k+ 2桁目以降の数がすべてd1未満なら良いので、min{ d1, dk+1 }* d1^n - (k + 1)
// 3. 上から1桁目の数が1以上d1未満で、2桁目以降の数がそれより小さければいい
// 4. 上から1桁目の数が1以上9未満で、2桁目以降の数がそれより小さければいい
int main() {
  ll L, R;
  cin >> L >> R;
  cout << count_snake_numbers(R) - count_snake_numbers(L - 1) << endl;
}

