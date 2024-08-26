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

int N;
vector<vector<int>> a;

// グループの幸福度を計算する
int calc(vector<int> &v) {
  if (v.size() <= 1) {
    return 0;
  }
  int res = 0;
  for(int i = 0; i < v.size() - 1; i++) {
    for(int j = i + 1; j < v.size(); j++) {
      res += a[v[i]][v[j]];
    }
  }
  return res;
}


vector<vector<int>> group(3);
int solve(int i) {
  if(i == N) {
    int res = 0;
    rep(j, 3) res += calc(group[j]);
    return res;
  }
  
  int ans = INT_MIN;
  rep(j, 3) {
    group[j].push_back(i);
    chmax(ans, solve(i + 1));
    group[j].pop_back();
  }
  return ans;
}

int main() {
  cin >> N;
  a = vector<vector<int>>(N, vector<int>(N));

  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      cin >> a[i][j];
    }
  }

  cout << solve(0) << endl;
}
