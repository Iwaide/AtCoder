#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> cards(N);
  rep(i, N) cin >> cards.at(i);
  int alice = 0;
  int bob = 0;
  rep(i, N) {
    int selected_index = 0;
    int selected = 0;
    rep(j, N) {
      if (cards.at(j) > selected) {
        selected = cards.at(j);
        selected_index = j;
      }
    }
    if (i % 2 == 0) {
      alice += selected;
    } else {
      bob += selected;
    }
    cards.at(selected_index) = 0;
  }
  cout << alice - bob << endl;
}
