#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  map<string, int> A; 
  rep(i, N) {
    string S;
    cin >> S;
    A[S] += 1;
  }
  int result = 0;
  for(auto pair: A) {
    if (pair.second % 2 == 1) {
      result++;
    }
  }
  cout << result << endl;
}
