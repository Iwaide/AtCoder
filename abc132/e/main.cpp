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

// けんけんぱで移動したときに取りうる値ってmod3しか無い気がする
// 1 -> 2
// 1 -> 2 -> 3 -> 4 -> 5 -> 1
//   -> 4 -> 6
//   -> 5
int main() {
  int N, M, S, T; cin >> N >> M;
  map<int, set<int>> sides;
  map<int, set<int>> mods;
  rep(i, M) {
    int u, v; cin >> u >> v;
    u--; v--;
    sides[u].insert(v);
  }
  cin >> S >> T; S--; T--;

  queue<int> q; q.push(S);
  vector<int> distances(N, -1);
  distances[S] = 0;
  mods[S].insert(0);
  while(!q.empty()) {
    vector<set<int>> vec(4);
    int p = q.front(); q.pop();
    vec[0].insert(p);
    // ケンケンパは3回移動
    // vec[3]がケンケンパしたときに取りうる場所
    rep2(i, 1, 4) {
      for(int x: vec[i - 1]) {
        vec[i].insert(all(sides[x]));
      }
    }
    int distance = distances[p] + 1;
    int mod = distance % 3;
    for(int x: vec[3]) {
      if (x == p) continue;
      if (!mods[x].count(mod)) {
        distances[x] = distance;
        mods[x].insert(mod);
        if (x == T) {
          cout << distances[x] << endl;
          return 0;
        } else {
          q.push(x);
        }
      }
    }
  }
  cout << -1 << endl;
}

