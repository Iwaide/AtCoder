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

// 回転寿司に1からNまでの番号がつけられたN人の人が訪れている
// 人iの美食度はAi
// M個の寿司が流れる、j番目に流れる寿司の美味しさはBj
// 人はAi以上の美味しさの寿司を取る。M個の寿司それぞれについてその寿司を誰が食べるか、あるいは誰も食べないか求めよ
int main() {
  int N, M; cin >> N >> M;
  vector<int> vec(200001, -1), B(M);
  rep(i, N) {
    int Ai; cin >> Ai;
    if (vec[Ai] == -1) {
      int j = Ai;
      while(vec[j] == -1 && j < 200001) {
        vec[j] = i;
        j++;
      }
    }
  }
  rep(i, M) {
    int Bi; cin >> Bi;
    if (vec[Bi] == -1) {
      cout << -1 << endl;
    } else {
      cout << vec[Bi] + 1 << endl;
    }
  }
}

