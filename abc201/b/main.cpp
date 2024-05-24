#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<pair<int, string>> mountains;
  rep(i, N) {
    string Si;
    int Ti;
    cin >> Si >> Ti;
    mountains.push_back(make_pair(Ti, Si));
  }
  sort(mountains.begin(), mountains.end(), greater<pair<int, string>>());
  cout << mountains.at(1).second << endl;
}

