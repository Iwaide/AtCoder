#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  map<int, vector<int>> A;
  rep(i, 2 * N) {
    int Ai;
    cin >> Ai;
    Ai--;
    A[Ai].push_back(i);
  }
  int result = 0;
  rep(i, N) {
    vector<int> pair = A.at(i);
    if (abs(pair.at(0) - pair.at(1)) == 2) result++;
  }
  cout << result << endl;
}

