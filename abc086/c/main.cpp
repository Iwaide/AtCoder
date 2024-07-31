#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N; cin >> N;
  pair<int, int> current{ 0, 0 };
  int current_time = 0;
  rep(i, N) {
    int ti, xi, yi;
    cin >> ti >> xi >> yi;
    int total = abs(xi - current.first) + abs(yi - current.second);
    int T = ti - current_time;
    if (T >= total && T % 2 == total % 2) {
      current_time = ti;
      current = make_pair(xi, yi);
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

