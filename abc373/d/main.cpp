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

// N頂点M辺の有向グラフ
// 各頂点に-10^18以上10^18以下の整数を書き込む方法で、次の条件を満たすものを1つ見つける
// 頂点iに書き込まれている値をxiとする、すべての辺jについてxvj - xuj = wjが成り立つ
// 普通に深さ優先探索で良かった…
map<int, vector<pair<int, ll>>> Sides;
vector<ll> ans;
void dfs(int u) {
  for(auto p : Sides[u]) {
    if (ans[p.first] == LONG_LONG_MAX) {
      ans[p.first] = ans[u] + p.second;
      dfs(p.first);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  rep(i, M) {
    int u, v; ll w;
    cin >> u >> v >> w;
    u--; v--;
    Sides[u].push_back({v, w});
    Sides[v].push_back({u, -w});
  }
  ans.resize(N, LONG_LONG_MAX);
  rep(i, N) {
    if(ans[i] == LONG_LONG_MAX) {
      ans[i] = 0;
      dfs(i);
    }
  }
  print_vector(ans);
}

