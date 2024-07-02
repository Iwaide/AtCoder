#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> C1(N), C2(N);
  rep(i, N) {
    int Ci, Pi;
    cin >> Ci >> Pi;
    if (Ci == 1) {
      C1.at(i) = Pi;
      C2.at(i) = 0;
    } else {
      C1.at(i) = 0;
      C2.at(i) = Pi;
    }
  }
  vector<int> C1Cs(N + 1), C2Cs(N + 1);
  rep(i, N) {
    C1Cs.at(i + 1) = C1Cs.at(i) + C1.at(i);
    C2Cs.at(i + 1) = C2Cs.at(i) + C2.at(i);
  }
  int Q;
  cin >> Q;
  rep(i, Q) {
    int Li, Ri;
    cin >> Li >> Ri;
    --Li;
    cout << C1Cs.at(Ri) - C1Cs.at(Li) << " ";
    cout << C2Cs.at(Ri) - C2Cs.at(Li) << endl;
  }
}

