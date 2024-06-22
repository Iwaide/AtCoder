#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int result = 0;
  rep(i, N) {
    string S;
    cin >> S;
    if (S == "Takahashi") {
      result++;
    }
  }
  cout << result << endl;
}

