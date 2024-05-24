#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0;
  cin >> a;
  int s3 = a % 10;
  int s2 = a % 100 / 10;
  int s1 = a / 100;

  cout << s1 + s2 + s3 << endl;
}
