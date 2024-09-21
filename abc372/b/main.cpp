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

// Nは1以上20以下
// Aiは10以下
int main() {
  int M;
  cin >> M;
  vector<int> ans;

  while(M > 0) {
    int Ai = 1;
    int i = 0;
    while(Ai <= M) {
      Ai *= 3;
      i++;
    }
    Ai /= 3;
    i--;
    M -= Ai;
    ans.push_back(i);
  }
  cout << ans.size() << endl;
  print_vector(ans);
}

