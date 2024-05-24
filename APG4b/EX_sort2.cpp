#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> nums;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    nums.push_back(make_pair(b, a));
  }
  sort(nums.begin(), nums.end());
  rep(i, N) {
    cout << nums.at(i).second << " " << nums.at(i).first << endl;
  }
}
