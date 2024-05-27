#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string O, E;
  cin >> O >> E;
  for(int i = 0; i <= O.size() * 2; i++) {
    int index = i / 2;
    if (i % 2 == 0) {
      if (index <= O.size() - 1) {
        cout << O.at(i / 2);
      }
    } else {
      if (index <= E.size() - 1) {
        cout << E.at(i / 2);
      }
    }
  }
  cout << endl;
}

