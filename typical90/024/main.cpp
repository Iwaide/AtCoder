#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
// 
// A = 1 ,3, 5, 4, 6
// B = 2, 5, 6, 1, 9 
// Aiを+-1で置き換える。ちょうどK回でAをBにできるか
int main() {
  int N; long long K; cin >> N >> K;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  long long cnt = 0;
  rep(i, N) cnt += abs(B[i]- A[i]);
  if (cnt > K) {
    cout << "No" << endl;
    return 0;
  }
  if (K % 2 == cnt % 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

