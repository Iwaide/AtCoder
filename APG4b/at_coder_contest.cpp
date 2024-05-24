#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string result;
  rep(i, 3) {
    string x;
    cin >> x;
    result += x.at(0);
  }
  cout << result << endl;
}
