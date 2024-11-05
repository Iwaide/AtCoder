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

// N個のタスクがある
// i個目のタスクはAi日目以降に実行でき、Biポイント獲得できる
// 1日ごとにタスクを1つ選んでそれを消化する
// 1以上N以下のすべての整数kに対して、これからk日間で得られるポイントの最大値を求めろ
int main() {
  int N;
  cin >> N;
  map<int, vector<int>> m;
  rep(i, N) {
    int Ai, Bi; cin >> Ai >> Bi;
    Ai--;
    m[Ai].push_back(Bi);
  }
  priority_queue<int> tasks;
  int ans = 0;
  rep(i, N) {
    for (int point : m[i]) tasks.push(point);
    ans += tasks.top();
    tasks.pop();
    cout << ans << endl;
  }
}
