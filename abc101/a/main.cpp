#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a = 0;
  rep(i, 4) {
    char op;
    cin >> op;
    if (op == '+') a++;
    if (op == '-') a--;
  }
  cout << a << endl;
}
