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

// 東西にN人並んでいる
// 各人の状態を表す長さNの文字列Sが与えられる
// 西からi番目の人はLなら西、Rなら東を見ている
// どの人も眼の前の人が自分と同じ方向を向いていれば幸福
// 眼の前に人がいない場合は幸福でない
// 下記の操作を0〜K回行う
// 1 <= l <= r <= N を満たす整数l,rを選ぶ
// 西からl, l + 1, ... r番目の人の列を180度回転させる
int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  int group = 0;
  for(int i = 0; i < S.size();) {
    int j = i + 1;
    while(S[i] == S[j] && j < S.size()) j++;
    i = j;
    group++;
  }
  cout << N - max(1, (group - K * 2)) << endl;
}

