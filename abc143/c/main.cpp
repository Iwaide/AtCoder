#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  string S;
  cin >> N >> S;
  int result = 0;
  for(int i = 0; i < S.size();) {
    int j = i + 1;
    while(j < S.size() && S.at(j) == S.at(j - 1)) {
      j++;
    }
    result++;
    i = j;
  }
  cout << result << endl;
}

