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
    cout << vec[i] << endl;
  }
}

int N;
vector<int> a, b, ans;
map<int, int> mapB;
bool dfs(int i) {
  if (i == N + 1) {
    if (a == b) {
      print_vector(ans);
      return true;
    } else  {
      return false;
    }
  }
  bool res = false;
  // indexより小さい数を突っ込んでみる
  for(int j = 1; j <= i; j++) {
    if (mapB[j] > 0) {
      mapB[j]--;
      a.insert(a.begin() + j - 1, j);
      ans.push_back(j);
      res |= dfs(i + 1);
      a.erase(a.begin() + j - 1);
      ans.pop_back();
      mapB[j]++;
    }
  }
  return res;
}

// すぬけ君は空の数列aを持っている
// aに対してN回の操作を行う
// i回目の操作では1 <= j <= iを満たす整数jを選びaの先頭からj番目にjを挿入するとができる
// 長さNの数列bが与えられる、N回の操作後にaがbと一致することがあるかどうか判定し
// 可能ならばそれを達成する操作手順の一例を示せ
int main() {
  cin >> N;
  b.resize(N);
  rep(i, N) {
    cin >> b[i];
    mapB[b[i]]++;
  }

  // 全部やってみればええんでない？
  if (!dfs(1)) {
    cout << - 1 << endl;
  }
}

