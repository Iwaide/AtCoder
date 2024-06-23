#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, Q;
  cin >> N >> Q;
  map<int, set<int>> Followees;
  map<int, set<int>> Followers;
  rep(i, Q) {
    int cmd;
    cin >> cmd;
    if(cmd == 1) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      Followees[a].insert(b);
      Followers[b].insert(a);
    } else if (cmd == 2) {
      int a;
      cin >> a;
      a--;
      for(int u : Followers[a]) {
        Followees[a].insert(u);
        Followers[u].insert(a);
      }
    } else if (cmd == 3) {
      int a;
      cin >> a;
      a--;
      // NOTE: 
      set<int> new_followees;
      for(int followee: Followees[a]) {
        for(int u: Followees[followee]) {
          if (u == a) continue;
          new_followees.insert(u);
        }
      }
      for(int u : new_followees) {
        Followees[a].insert(u);
        Followers[u].insert(a);
      }
    }
  }
  rep(i, N) {
    set<int> followee = Followees[i];
    rep(j, N) {
      if (followee.count(j)) {
        cout << "Y";
      } else {
        cout << "N";
      }
    }
    cout << endl;
  }
}

