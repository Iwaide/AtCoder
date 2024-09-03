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

// 幅優先探索をしていって、初めて訪れるノードの前のノードに繋がっていればいい？
int main() {
  int N, M; cin >> N >> M;
  vector<int> from(N, -1);
  map<int, set<int>> graph;
  rep(i, M) {
    int A, B; cin >> A >> B;
    A--; B--;
    graph[A].insert(B);
    graph[B].insert(A);
  }

  queue<int> q; q.push(0);
  while(!q.empty()) {
    int p = q.front(); q.pop();
    for(int node : graph[p]) {
      if (from[node] == -1) {
        from[node] = p;
        q.push(node);
      }
    }
  }

  rep2(i, 1, N) {
    if (from[i] == -1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  rep2(i, 1, N) {
    cout << ++from[i] << endl;
  }
}

