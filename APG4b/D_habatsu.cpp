#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int N, M;
vector<vector<int>> relationships;
vector<bool> in_group;

bool is_addable(int index) {
  bool result = true;
  rep(i, N) {
    if (!in_group.at(i)) continue;
    bool addable = false;
    rep(j, M) {
      if (relationships.at(j).at(0) == i && relationships.at(j).at(1) == index) {
        addable = true;
      }
      if (relationships.at(j).at(1) == i && relationships.at(j).at(0) == index) {
        addable = true;
      }
    }
    if (!addable) return false;
  }
  return true;
}

int grouping(int index) {
  int member_count = 0;
  rep(i, N) if (in_group.at(i)) member_count++;

  if (index == N) {
    return member_count;
  }

  int tmp1 = 0;
  // cout << index << "is_addable:" << is_addable(index) << "member_count:" << member_count << endl;
  if (member_count == 0 || is_addable(index)) {
    in_group.at(index) = true;
    tmp1 = grouping(index + 1);
  }
  in_group.at(index) = false;
  int tmp2 = grouping(index + 1);

  return max(tmp1, tmp2);
}

int main() {
  cin >> N >> M;
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    relationships.push_back(vector<int>{ x - 1, y - 1});
  }
  rep(i, N) in_group.push_back(false);
  cout << grouping(0) << endl;
}
