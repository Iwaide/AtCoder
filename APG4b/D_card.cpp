#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> cards(n);
  rep(i, n) cin >> cards.at(i);
  set<int> result;

  sort(cards.begin(), cards.end());
  do {
    string S = "";
    rep(i, k) S += to_string(cards.at(i));
    result.insert(stoi(S));
  } while(next_permutation(cards.begin(), cards.end()));

  cout << result.size() << endl;
}
