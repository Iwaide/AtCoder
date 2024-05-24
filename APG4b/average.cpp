#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> scores(N);
  int sum = 0;
  rep(i, N) {
    int A;
    cin >> A;
    sum += A;
    scores.at(i) = A;
  }
  int avg = sum / N;
  rep(i, N) {
    int answer = avg - scores.at(i);
    if (answer < 0) {
      answer *= -1;
    }
    cout << answer << endl;
  }
}

