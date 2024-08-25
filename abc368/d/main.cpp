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

int main() {
  int N, K;
  cin >> N >> K;
  map<int, set<int>> graph;
  set<int> res;
  rep(i, N) res.insert(i);
  vector<int> degree(N, 0);
  rep(i, N - 1) {
    int Ai, Bi; cin >> Ai >> Bi;
    Ai--; Bi--;
    graph[Ai].insert(Bi);
    graph[Bi].insert(Ai);
    degree[Ai]++; degree[Bi]++;
  }
  set<int> V;
  rep(i, K) {
    int vi; cin >> vi; vi--;
    V.insert(vi);
  }
  queue<int> que;
  rep(i, N) {
    if (degree[i] == 1) {
      que.push(i);
    }
  }
  vector<bool> explored(N, false);

  while(!que.empty()) {
    int z = que.front(); que.pop();
    explored[z] = true;
    // 葉が保護に含まれていたら？
    // true => 何もしない
    // false => treeから削除する(resから消す、紐づく頂点のdegreeを減らす, degreeが変わるはずなので1になったやつをqueに突っ込む)
    if (!V.count(z)) {
      res.erase(z);
      for(int p: graph[z]) {
        degree[p]--;
        if (!explored[p] && degree[p] == 1) {
          que.push(p);
        }
      }
    }
  }
  cout << res.size() << endl;
}

