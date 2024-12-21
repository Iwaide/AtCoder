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

// A, B, Cがある
// 2つ以上のグループに分けて、それぞれのグループ内の数の和を等しくできるか判定せよ
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  bool can = false;
  can |= (A + B == C);
  can |= (A + C == B);
  can |= (B + C == A);
  can |= (A == B && B == C);
  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

