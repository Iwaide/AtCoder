#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int R, G, B;
  string C;
  cin >> R >> G >> B >> C;
  if (C == "Red") {
    cout << min(G, B) << endl;
  } else if (C == "Green") {
    cout << min(R, B) << endl;
  } else {
    cout << min(R, G) << endl;
  }
}

