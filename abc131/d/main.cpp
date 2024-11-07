#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()
template<typename T>
void print_vector(vector<T> &vec) {
  rep(i, vec.size()) {
    if (i != vec.size() - 1) {
      cout << vec[i] << " ";
    } else {
      cout << vec[i] << endl;
    }
  }
}

// N件の仕事がある
// 仕事iを終えるにはAi時間かかる、締切はBi
// 締切までにすべての仕事を終わらせられるならYesできないならNo
int main() {
  int N; cin >> N;
  vector<int> A(N);
  set<int> B;
  map<int, vector<int>> simekiri;
  rep(i, N) {
    int Bi;
    cin >> A[i] >> Bi;
    B.insert(Bi);
    simekiri[Bi].push_back(i);
  }

  // 普通に締切順で最短でやっていけばいいのでは
  ll current = 0;
  for(int b : B) {
    for(int ai: simekiri[b]) {
      current += A[ai];
    }
    if (current > b) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

