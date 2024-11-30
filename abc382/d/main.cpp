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

// 整数NとMが与えられる
// 以下の条件をすべて満たす長さNの整数列(A1, A2 ,,, AN)を辞書順にすべて出力せよ
// 1 <= Ai Aiは1以上
// 2以上N以下の各整数iに対してA(i-1) + 10 <= Ai, Aiは前の要素より10以上大きい
// AN <= M 最後の要素はM以下
// 2 <= N <= 12
// 10N - 9 <= M <= 10N
// 111 <= M <= 120
// なんか深さ優先とかで行けばいい気もする
vector<int> vec;
vector<vector<int>> ans;
int N, M;

void dfs(int i) {
  if (i == N) {
    ans.push_back(vec);
    return;
  }
  int back = vec[i - 1];
  for(int j = back + 10; j <= M - (N - (i + 1)) * 10; j++) {
    vec.push_back(j);
    dfs(i + 1);
    vec.pop_back();
  }
  return;
}
int main() {
  cin >> N >> M;
  for(int i = 1; i <= M - ((N - 1) * 10); i++) {
    vec.push_back(i);
    dfs(1);
    vec.pop_back();
  }
  cout << ans.size() << endl;
  for(auto v : ans) {
    print_vector(v);
  }
}
