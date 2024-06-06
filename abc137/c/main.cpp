#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  map<string, vector<int>> Smap;
  rep(i, N) {
    string Si;
    cin >> Si;
    sort(Si.begin(), Si.end());
    if (Smap.count(Si)) {
      Smap.at(Si).push_back(i);
    } else {
      Smap.insert(make_pair(Si, vector<int> { i }));
    }
  }
  long long result = 0;
  for(auto res : Smap) {
    long long size = res.second.size();
    if (size == 1) continue;
    result += (1LL * size * (size - 1)) / 2;
  }
  cout << result << endl;
}
