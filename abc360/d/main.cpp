#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N, T;
  cin >> N >> T;
  string S;
  cin >> S;
  vector<long long> toLeft;
  vector<long long> toRight;
  rep(i, N) {
    long long Xi;
    cin >> Xi;
    if (S.at(i) == '0') {
      toLeft.push_back(Xi);
    } else {
      toRight.push_back(Xi);
    }
  }
  sort(toLeft.begin(), toLeft.end());
  long long ans = 0;
  rep(i, toRight.size()) {
    long long minimum = toRight.at(i);
    long long maximum = minimum + T * 2;
    auto min_pos = lower_bound(toLeft.begin(), toLeft.end(), minimum);
    auto max_pos = lower_bound(toLeft.begin(), toLeft.end(), maximum);

    int min_index = -1;
    int max_index = -1;

    if (min_pos != toLeft.end()) {
      min_index = distance(toLeft.begin(), min_pos);
    }
    if (max_pos != toLeft.end() && *max_pos <= maximum) {
      max_index = distance(toLeft.begin(), max_pos);
    } else {
      // max_posがmaximumより大きい場合、その1つ前を指す
      if (max_pos != toLeft.begin()) {
        max_pos--;
        max_index = distance(toLeft.begin(), max_pos);
      } else {
        max_index = -1;
      }
    }

    if (min_index != -1 && max_index != -1 && min_index <= max_index) {
      ans += (max_index - min_index + 1);
    }
  }
  cout << ans << endl;
}

