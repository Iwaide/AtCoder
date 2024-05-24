#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int N;
vector<int> t;
vector<bool> is_grill1;

int grill(int index) {
  if (index == N) {
    int grill1 = 0;
    int grill2 = 0;
    rep(i, N) {
      if (is_grill1.at(i)) {
        grill1 += t.at(i);
      } else {
        grill2 += t.at(i);
      }
    }
    return max(grill1, grill2);
  }
}

int main() {
  cin >> N;
  rep(i, N) {
    int time;
    cin >> time;
    t.push_back(time);
    is_grill1.push_back(false);
  }
  cout << grill(0) << endl;
}
