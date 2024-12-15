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

// Div1: レート1600以上2799以下
// Div2: レート1200以上2399以下
// N会のARCに参加する
// DivDi, 成績Ai
// 高橋くんがレーティング更新の対象なら、コンテスト開始時のレーティングをTとして、
// 更新後のレーティングはT + Aiとなる。
// 対象でなければ変化しない
// N回のARCを終えた後のレーティングを求めよ
int main() {
  int N, R;
  cin >> N >> R;
  rep(i, N) {
    int Di, Ai;
    cin >> Di >> Ai;
    if (Di == 1) {
      if (R >= 1600 && R <= 2799) {
        R += Ai;
      }
    } else if (Di == 2) {
      if (R >= 1200 && R <= 2399) {
        R += Ai;
      }
    }
  }
  cout << R << endl;
}

