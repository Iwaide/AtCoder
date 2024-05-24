#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a = N / 1000;
  int b = N % 1000 / 100;
  int c = N % 100 / 10;
  int d = N % 10;
  if (a == b && b == c) {
    cout << "Yes" << endl;
  } else if (b == c && c == d){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
