#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<long long, int>> AB;
  rep(i, N) {
    long long A;
    int B;
    cin >> A >> B;
    AB.push_back(make_pair(A, B));
  }
  sort(AB.begin(), AB.end());
  long long result = 0;
  rep(i, N) {
    int count = min(M, AB.at(i).second);
    M -= count;
    result += count * AB.at(i).first;
    if (count == 0) break;
  }
  cout << result << endl;
}

