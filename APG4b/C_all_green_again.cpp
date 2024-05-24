  #include <bits/stdc++.h>
  using namespace std;
  #define rep(i, n) for (int i = 0; i < (int)(n); i++)
  #define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

  vector<int> p;
  vector<int> c;
  vector<bool> check;
  int D, G;

  int answer(int index) {
    if (index == D) {
      int answer_count = 0;
      int score = 0;
      rep(i, D) {
        if (check.at(i)) {
          answer_count += p.at(i);
          score += (i + 1) * 100 * p.at(i);
          score += c.at(i);
        }
      }
      if (score >= G) return answer_count;
      for(int i = D - 1; i >= 0; i--) {
        if (check.at(i)) continue;

        int additional =
          (G - score + (i + 1) * 100 - 1) / ((i + 1) * 100);
        if (p.at(i) >= additional) {
          return answer_count + additional;
        }
      }
      return 100000;
    }

    check.at(index) = true;
    int tmp1 = answer(index + 1);
    check.at(index) = false;
    int tmp2 = answer(index + 1);
    return min(tmp1, tmp2);
  }

  int main() {
    cin >> D >> G;
    rep(i, D) {
      int count, bonus;
      cin >> count >> bonus;
      p.push_back(count);
      c.push_back(bonus);
      check.push_back(false);
    }
    cout << answer(0) << endl;
  }
