#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vector<int> A(N + 1);
  rep(i, N + 1) {
    if (i == K) {
      A.at(i) = X;
    } else {
      int Ai; cin >> Ai;
      A.at(i) = Ai;
    }
  }
  for (int i = 0; i < N + 1; i++) {
    cout << A.at(i);
    if (i == N) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

