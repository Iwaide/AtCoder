#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> result;
  rep(i, N) {
    int K;
    cin >> K;
    vector<int> A(K);
    rep(j, K) cin >> A.at(j);
    if (i == 0) result = A;
    vector<int> tmp_result;
    sort(result.begin(), result.end());
    sort(A.begin(), A.end());
    set_intersection(A.begin(), A.end(), result.begin(), result.end(), inserter(tmp_result, tmp_result.end()));
    result = tmp_result;
  }
  cout << result.size() << endl;
}

