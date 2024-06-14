#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  string result;
  for(int i = 0; i < S.size();) {
    int j = i + 1;
    while(j < S.size() && S.at(j) == S.at(j - 1)) {
      j++;
    }
    result += S.at(i) + to_string(j - i); 
    i = j;
  }
  cout << result << endl;
}

