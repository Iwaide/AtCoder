#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  rep(i, N) {
    cin >> H.at(i);
  }
  int result = 0;
  rep(i, N) {
    int Hi = H.at(i);
    if (M >= Hi) {
      M -= Hi;
      result++;
    } else {
      break;
    }
  }
  cout << result << endl;
}

