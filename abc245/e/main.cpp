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
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> Choco(N), Box(M);
  rep(i, N) cin >> Choco[i].first;
  rep(i, N) cin >> Choco[i].second;

  rep(i, M) cin >> Box[i].first;
  rep(i, M) cin >> Box[i].second;
  // チョコ取る
  sort(all(Choco)); sort(all(Box));
  int i = 0, res = 0;
  multiset<int> width;
  rep(j, M) {
    auto b = Box[j];
    while(i < N && Choco[i].first <= Box[j].first) {
      width.insert(Choco[i].second);
      i++;
    }
    if (width.empty()) continue;

    auto it = width.upper_bound(b.second);
    if (it != width.begin()) {
      --it;
      width.erase(it);
      res++;
    }
  }
  if (res == N) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
