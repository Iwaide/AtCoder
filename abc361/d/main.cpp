#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  S += "..";
  T += "..";

  map<string, int> dist;
  queue<string> q;
  dist[S] = 0; q.push(S);

  while(!q.empty()) {
    string s = q.front(); q.pop();
    // .の位置を取得する
    int j = 0;
    while(s[j] != '.') ++j;
    rep(i, N + 1) {
      if (s[i] == '.' || s[i + 1] == '.') continue;
      string ns = s;
      swap(ns[i], ns[j]);
      swap(ns[i+1], ns[j+1]);
      if (dist.count(ns)) continue;
      dist[ns] = dist[s] + 1;
      q.push(ns);
    }
  }
  if (dist.count(T)) {
    cout << dist[T] << endl;
  } else {
    cout << -1 << endl;
  }
}

