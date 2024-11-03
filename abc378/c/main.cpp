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

// 長さNの正整数列Aがある
// 同じ長さのBを求めよ
// i = 1, 2...NについてBiは下記となる
// Aiと等しい要素がiの直前に出現した位置をBiとする
// そのような位置が存在しなければBi = -1とする
int main() {
  int N;
  cin >> N;
  map<int, int> Amap;
  rep(i, N) {
    int Ai; cin >> Ai;
    if (Amap[Ai] == 0) {
      cout << -1;
    } else {
      cout << Amap[Ai];
    }
    Amap[Ai] = i + 1;
    if (i != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

