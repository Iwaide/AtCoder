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

// N頂点M辺の単純有向グラフがある
// 頂点1を含む閉路があるかを判定して、存在する場合はそのような閉路のうち、
// 辺数が最小の閉路の辺数をもとめる
// 1から出発して幅優先で1に戻ればいいんじゃないの？
int main() {
  int N, M;
  cin >> N >> M;
  map<int, vector<int>> G;
  rep(i, M) {
    int ai, bi;
    cin >> ai >> bi; ai--, bi--;
    G[ai].push_back(bi);
  }
  queue<int> q;
  q.push(0);
  vector<int> visited(N, -1);
  visited[0] = 0;
  while(!q.empty()) {
    int p = q.front(); q.pop();
    for(auto s : G[p]) {
      // 閉路になった
      if (s == 0) {
        cout << visited[p] + 1 << endl;
        return 0;
      } else {
        if (visited[s] == -1) {
          visited[s] = visited[p] + 1;
          q.push(s);
        }
      }
    }
  }
  cout << -1 << endl;
}

