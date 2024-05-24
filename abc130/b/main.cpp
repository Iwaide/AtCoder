#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> D;
  int result = 1;
  D.push_back(0);
  rep(i, N) {
    int L;
    cin >> L;
    int Di = D.at(i) + L;
    if (Di <= X) result++;
    D.push_back(Di);
  }
  cout << result << endl;
}

