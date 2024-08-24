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

map<int, set<int>> graph;
queue<int> que;
int N, K;
set<int> V;
set<int> used

void dfs(int current, int cnt) {
  if (used.size() == N) {
    return;
  }
  used.insert(current);
  if (V.count(current)) {
    cnt++;
  }
  bool has_node = false;
  for(auto n : graph[current]) {
    
  }
}

int main() {
  cin >> N >> K;
  rep(i, N - 1) {
    int Ai, Bi; cin >> Ai >> Bi;
    Ai--; Bi--;
    graph[Ai].insert(Bi);
    graph[Bi].insert(Ai);
  }
  rep(i, K) {
    int vi; cin >> vi; vi--;
    V.insert(vi);
  }
  dfs(V[0], 0);

  // for(auto t: tree) {
  //   if (t.second.size() == 0) {
  //     que.push(t.first);
  //   }
  // }
  // set<int> ans;

  // while(!que.empty()) {
  //   int n = que.front(); que.pop();
  //   if (V.count(n) || ans.count(n)) {
  //     ans.insert(n);
  //   }
  //   for(int p : reverse[n]) {
  //     que.push(p);
  //   }
  // }
  // cout << ans.size() << endl;
}

