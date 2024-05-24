#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> buttons(N);
  rep(i, N) {
    int A;
    cin >> A;
    buttons.at(i) = A;
  }
  int next = buttons.at(0);
  int counter = 1;
  while(next != 2 && counter <= N) {
    next = buttons.at(next - 1);
    counter++;
  }
  if (next == 2) {
    cout << counter << endl;
  } else {
    cout << -1 << endl;
  }
}

// ループ検知入れたけどなんかこっちのほうが遅かった
int main() {
  int N;
  cin >> N;
  vector<int> buttons(N);
  rep(i, N) {
    int A;
    cin >> A;
    buttons.at(i) = A;
  }
  int next = buttons.at(0);
  int counter = 1;
  while(next != 2 && next != -1) {
    int tmp_next = next;
    next = buttons.at(tmp_next - 1);
    buttons.at(tmp_next - 1) = -1;
    counter++;
  }
  if (next == 2) {
    cout << counter << endl;
  } else {
    cout << -1 << endl;
  }
}