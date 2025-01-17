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

// H = (3, 1, 4, 1, 5, 9, 2, 6)
// i = 7 Hi = 6 {}
// i = 6 Hi = 2 {6}
// i = 5 Hi = 9 {2, 6}
// i = 4 Hi = 5 {9}
// i = 3 Hi = 1 {5, 9}
// i = 2 Hi = 4 {1, 5, 9}
// i = 1 Hi = 1 {4, 5, 9}
// i = 0 Hi = 3 {1, 4, 5, 9}
// ビルHiを追加するとき、前回求めたリストについてHiよりも低い建物を削除していき新たにビルHiを挿入すｒ
int main() {
  int N; cin >> N;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  vector<int> res;
  stack<int> st;
  for(int i = N - 1; i >= 0; i--) {
    res.push_back(st.size());
    while(!st.empty() && st.top() < H[i]) st.pop();
    st.push(H[i]);
  }
  reverse(all(res));
  print_vector(res);
}
