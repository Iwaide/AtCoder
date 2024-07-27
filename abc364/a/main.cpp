#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  bool before = false;
  rep(i, N - 1) {
    string Si; cin >> Si;
    if (Si == "sweet") {
      if (before) {
        cout << "No" << endl;
        return 0;
      } else {
        before = true;
      }
    } else {
      before = false;
    }
  }
  cout << "Yes" << endl;
}

