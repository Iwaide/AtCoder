#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int D;
long long G;
vector<int> p;
vector<int> c;
vector<bool> a;

int answer(int index) {
  if (index == D) {
    int answer_count = 0;
    int score = 0;
    rep(i, D) {
      if (a.at(i)) {
        answer_count += p.at(i);
        score += p.at(i) * (i + 1) * 100 + c.at(i);
      }
    }
    if (score >= G) return answer_count;
    for (int i = D - 1; i >= 0; i--) {
      if (a.at(i)) continue;
      int additional = (G - score + ((i + 1) * 100) - 1) / ((i + 1) * 100);
      if (additional <= p.at(i)) {
        return answer_count + additional;
      } else {
        return 100000;
      }
    }
  }

  a.at(index) = true;
  int tmp1 = answer(index + 1);
  a.at(index) = false;
  int tmp2 = answer(index + 1);
  return min(tmp1, tmp2);
}
int main() {
  cin >> D >> G;
  rep(i, D) {
    int pi, ci;
    cin >> pi >> ci;
    p.push_back(pi);
    c.push_back(ci);
    a.push_back(false);
  }
  cout << answer(0) << endl;
}

