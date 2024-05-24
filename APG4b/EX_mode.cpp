#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  map<int, int> modes;
  rep(i, N) {
    int A;
    cin >> A;
    if (modes.count(A)) {
      modes.at(A) += 1;
    }
  }
}
