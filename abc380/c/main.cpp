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

// 0,1のみからなるNの文字列S
// Sの中で先頭からK番目の1の塊をK-1番目の1の塊の直後まで移動した文字列を出力せよ
int main() {
  int N, K; cin >> N >> K;
  string S;
  cin >> S;
  vector<pair<char, int>> vec;
  int i = 0;
  while(i < S.size()) {
    int j = i;
    while(S[j] == S[i]) j++;
    vec.push_back({ S[i], j - i });
    i = j;
  }
  int k = 0;
  rep(i, vec.size()) {
    auto p = vec[i];
    if (p.first == '1') k++;
    if (k == K && p.first == '1') continue;
    rep(_, p.second) cout << p.first;
    if (p.first == '1' && k == (K - 1)) {
      int k2 = i + 1;
      while(vec[k2].first == '0') k2++;
      rep(_, vec[k2].second) cout << vec[k2].first;
    }
  }
  cout << endl;
}

