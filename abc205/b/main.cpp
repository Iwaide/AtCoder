#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);

  sort(A.begin(), A.end());
  rep(i, N) {
    if (A.at(i) != (i + 1)) {
      cout << "No" << endl;
      return 0;
    } 
  }
  cout << "Yes" << endl;
}

