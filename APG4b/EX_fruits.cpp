#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  rep(i, N) cin >> A.at(i);
  rep(i, N) cin >> P.at(i);
  int counter = 0;
  for(int apple : A) {
    for(int pine: P) {
      if (apple + pine == S) {
        counter++;
      }
    }
  }
  cout << counter << endl;
}
