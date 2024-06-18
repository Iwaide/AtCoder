#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  vector<int> a(S.size());
  vector<pair<char, int>> s;
  vector<int> result;
  for (int i = 0; i < S.size();) {
    int j = i + 1;
    while(j < S.size() && S.at(i) == S.at(j)) j++;
    s.push_back(make_pair(S.at(i), j - i));
    i = j;
  }
  for(int i = 0; i < s.size() - 1; i += 2) {
    pair<char, int> r = s.at(i);
    pair<char, int> l = s.at(i + 1);
    rep(j, r.second - 1) result.push_back(0);
    int cnt = max(r.second - 1, l.second - 1);
    int tmp1 = (r.second + 2 - 1) / 2 + (l.second / 2);
    int tmp2 = (l.second + 2 - 1) / 2 + (r.second / 2);
    // if (cnt % 2 == 1) swap(tmp1, tmp2);
    result.push_back(tmp1);
    result.push_back(tmp2);
    rep(i, l.second - 1) result.push_back(0);
  }
  rep(i, result.size()) {
    if (i != 0) cout << " ";
    cout << result.at(i);
  }
  cout << endl;
}

