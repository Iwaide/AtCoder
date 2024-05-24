#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<long long> lucas(N + 1);
  lucas.at(0) = 2;
  lucas.at(1) = 1;
  rep2(i, 2, N + 1) {
    lucas.at(i) = lucas.at(i - 1) + lucas.at(i - 2);
  }
  cout << lucas.at(N) << endl;
}
