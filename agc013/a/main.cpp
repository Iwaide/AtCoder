#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  rep(i, N) cin >> A.at(i);

  int result = 0;
  for(int i = 0; i < N;) {
    if (i == N - 1) {
      result++;
      break;
    }
    int j = i + 1;
    // 変化が出るまで探索
    while(j < N && A.at(i) == A.at(j)) j++;
    bool is_ascending = A.at(i) < A.at(j);
    // 違うやつにぶつかるまで探索
    if (is_ascending) {
      while(j < N && A.at(j - 1) <= A.at(j)) j++;
    } else {
      while(j < N && A.at(j - 1) >= A.at(j)) j++;
    }
    result++;
    i = j;
  }
  cout << result << endl;
}

// 他の解法
// https://atcoder.jp/contests/agc013/submissions/54493382
// up, downをtrueで初期化しておき、そうでないものが出たらfalseを突っ込む
// 両方がfalseになった時点で矛盾してるということで、ans++してup, downを再度trueで初期化
