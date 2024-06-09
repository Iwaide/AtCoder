#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int result = 0;
  set<string> S;
  rep(i, N) {
    string Si;
    cin >> Si;
    S.insert(Si);
  }
  cout << S.size() << endl;
}

