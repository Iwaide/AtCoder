#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a.at(i);
  int result = 0;
  for(int i = 0; i < N - 1;) {
    int j = i + 1;
    while (j < N && a[i] == a[j]) j ++;
    // 奇数の場合 1, 1, 1 を 1, 2, 1に変える
    // 偶数個の場合 1, 1, 1, 1を1, 2, 1, 2に変える
    // つまり切り捨ての2で割った答えとなる
    result += (j - i) / 2;
    i = j;
    // if (a.at(i) == a.at(j)) {
    //   a.at(j) = 101;
    //   result++;
    // }
    // i = j;
  } 
  cout << result << endl;
}

