#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int D, G;
vector<int> p;
vector<int> c;
vector<bool> com;

int answer(int index) {
  // ベースケース
  // indexをすすめていってDに達したら終わってるのでスコア計算
  if (index == D) {
    int score = 0;
    int answer_count = 0;
    rep(i, D) {
      if (com.at(i)) {
        score += (i + 1) * 100 * p.at(i);
        score += c.at(i);
        answer_count += p.at(i);
      }
    }
    if (score >= G) return answer_count;

    for (int i = D - 1; i >= 0; i--) {
      if (!com.at(i)) {
        // (i + 1) * 100  - 1のやつは切り捨て処理
        // 普通に計算したら1800 - 1000 / 300 みたいな感じなんだけど
        // 切り上げて計算しないといけないからやってる
        int tmp = (G - score + (i + 1) * 100  - 1) / ((i + 1) * 100);
        if (p.at(i) > tmp) return answer_count + tmp;
      }
    }
    // minで比較しないといけないので足りなかったら採用されないように大きい数字を置いておく
    return 1000000;
  }

  com.at(index) = true;
  int tmp1 = answer(index + 1);
  com.at(index) = false;
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
    com.push_back(false);
  }

  cout << answer(0) << endl;
}
