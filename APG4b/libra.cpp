#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int left = A + B;
  int right = C + D;
  string result;
  if (left > right) {
    result = "Left";
  } else if (left == right) {
    result = "Balanced";
  } else {
    result = "Right";
  }
  cout << result << endl;
}
