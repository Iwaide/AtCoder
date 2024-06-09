#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int result = 1000000;
  rep(i, N) {
    long long Ai;
    cin >> Ai;
    int counter = 0;
    while(true) {
      if (Ai % 2 == 0) {
        counter++;
        Ai /= 2;
      } else {
        break;
      }
    }
    result = min(result, counter);
  }
  cout << result << endl;
}

