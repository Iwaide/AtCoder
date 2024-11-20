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

int main() {
  string S;
  cin >> S;
  vector<int> vec;
  int i = 0;
  while(i < S.size()) {
    int j = i + 1;
    while(S[j] != '|' && j < S.size() - 1) j++;
    vec.push_back(j - i - 1);
    i = j;
  }
  vec.pop_back();
  print_vector(vec);
}

