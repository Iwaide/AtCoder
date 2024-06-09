#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  set<long long> s;
  rep(i, N) {
    long long Ai;
    cin >> Ai;
    s.insert(Ai);
  }
  cout << (s.size() == N ? "YES" : "NO") << endl;
}

