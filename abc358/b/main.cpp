#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, A;
  cin >> N >> A;
  int current_time = 0;
  rep(i, N) {
    int Ti;
    cin >> Ti;
    if (current_time >= Ti) {
      current_time += A;
    } else {
      current_time = Ti + A;
    }
    cout << current_time << endl;
  }
}
