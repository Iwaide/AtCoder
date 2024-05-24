#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int counter = 1;
  int before;
  cin >> before;
  // 1が上行-1が下降
  int direction = 0;
  rep2(i, 1, N) {
    int current;
    cin >> current;
    if (before == current) continue;

    if (before > current) {
      if (direction == 0) {
        direction = 1;
      } else if (direction == -1) {
        counter++;
        direction = 0;
      }
    } else {
      if (direction == 0) {
        direction = -1;
      } else if (direction == 1) {
        counter++;
        direction = 0;
      }
    }
    before = current;
  }
  cout << counter << endl;
}
