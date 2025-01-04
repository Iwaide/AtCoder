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
// 4325で考える
ll count_snake_numbers(ll num) {
  string str = to_string(num);
  ll ans = 0;
  // 999までのへび数を求める
  for(int i = 0; i < str.size() - 2; i++) {
    for(int j = 1; j < 10; j++) {
      ll tmp = j;
      for(int k = 0; k < i; k++) tmp *= j;
      ans += tmp;
    }
  }
  // 最大位の数
  int a = str[0] - '0';
  vector<int> vec;
  // 4323を考える
  for(int i = 1; i < str.size(); i++) {
    // 組み合わせの数
    vec.push_back(min(a - 1, str[i] - '0') + 1);
  }
  ll tmp = 1;
  for(auto v : vec) tmp *= v;
  // 4323~4000まで求めた
  ans += tmp;
  a--;
  // 3222 ~ 1000までを求める
  while(a > 0) {
    vector<int> vec2;
    for(int i = 1; i < str.size(); i++) {
      vec2.push_back(a);
    }
    ll tmp2 = 1;
    for(auto v : vec2) tmp2 *= v;
    ans += tmp2;
    a--;
  }
  return ans;
}

// 10進数表記したときに、先頭の桁の数字がそれ以外のどの桁の数字よりも心に大きくなるものをへび数と呼ぶ
// L以上R以下のへび数が何個あるかもとめよ
// とりあえず桁数-1までは求められる
// 99 の場合 1 + 2 + ... + 9
// 999 の場合 1 * 1 + 2 * 2 ... + 9 * 9
// 例えば4325の1000までの数を求めたいときは
// 
int main() {
  // ll L, R; cin >> L >> R;
  // cout << count_snake_numbers(R) - count_snake_numbers(L) << endl; 
  ll L; cin >> L;
  cout << count_snake_numbers(L) << endl;
}

