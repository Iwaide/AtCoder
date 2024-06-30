#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> W(N);
  map<int, set<int>> Boxes;
  rep(i, N) {
    int Ai;
    cin >> Ai; Ai--;
    Boxes[Ai].insert(i);
  }
  rep(i, N) {
    long long Wi;
    cin >> Wi;
    W.at(i) = Wi;
  }
  long long ans = 0;
  for(auto box: Boxes) {
    vector<int> weights;
    if (box.second.size() > 1) {
      for(int i : box.second) {
        weights.push_back(W[i]);
      }
    }
    sort(weights.begin(), weights.end());
    rep(i, box.second.size() - 1) {
      ans += weights.at(i);
    }
  }
  cout << ans << endl;
}

