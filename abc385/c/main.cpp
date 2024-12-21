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

// N棟のビルが等間隔に1列に並んでいる
// 選んだビルたちは高さが等しい
// 選んだビルたちは等間隔に並んでいる
// 最大でいくつビルを選ぶことができるか？
// mapでID取ってくで良さそう
int main() {
  int N;
  cin >> N;
  map<int, vector<int>> H;
  rep(i, N) {
    int Hi; cin >> Hi;
    H[Hi].push_back(i);
  }
  int ans = 0;
  for(auto h : H) {
    vector<int> hi = h.second;
    if (hi.size() <= 2) chmax(ans, (int) hi.size());

    for(int i = 0; i < hi.size(); i++) {
      for(int j = i + 1; j < hi.size(); j++) {
        int distance = hi[j] - hi[i];
        int next = distance + hi[j];
        int cnt = 2;
        while(binary_search(all(hi), next)) {
          cnt++;
          next += distance;
        }
        chmax(ans, cnt);
      }
    }
  }
  cout << ans << endl;
}

