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

// N人の宇宙人がおり、全員未成年
// i人目の宇宙人はAi個の石を持っており、ちょうどi年後に成人します
// この星では石を1個以上所持している成人全員が成人する宇宙人に成人祝として石を1個渡します
// N年後に各宇宙人が所持している石の個数を求めよ
// priority_queueでの解法
// int main() {
//   int N; cin >> N;
//   vector<int> A(N);
//   rep(i, N) cin >> A[i];
//   // 石を持っている成人の集合
//   priority_queue<int, vector<int>, greater<int>> que;
//   rep(i, N) {
//     // 成人の数だけお祝いしてもらえる
//     A[i] += que.size();
//     // 残りの年数で配る石の数
//     int rest = min(A[i], N - 1 - i);
//     A[i] -= rest;
//     // 経過年数 + 配る石の数
//     // すべての数から-1するのではなく、年数を足した数を入れておいて年数以下の数を消す
//     que.push(i + rest);
//     while(!que.empty() && que.top() <= i) que.pop();
//   }
//   rep(i, N) {
//     if (i) cout << " ";
//     cout << A[i];
//   }
//   cout << endl;
// }

// // 解法2
// int main() {
//   int N; cin >> N;
//   vector<int> A(N);
//   rep(i, N) cin >> A[i];
//   // index年後に石がなくなる成人
//   vector<int> R(N + 1, 0);
//   // 石を持ってる成人
//   int S = 0;
//   rep(i, N) {
//     S -= R[i];
//     // 石を持っている成人を足す
//     A[i] += S;
//     // 動く石
//     int moved = min(A[i], N - 1 - i);
//     A[i] -= moved;
//     R[i + moved + 1]++;
//     S++;
//   }
//   rep(i, N) {
//     if (i) cout << " ";
//     cout << A[i];
//   }
//   cout << endl;
// }

// いもす法
// 区間に+1 ~ -1する
int main() {
int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  vector<int> imos(N + 1, 0);
  int cumsum = 0;
  rep(i, N) {
    cumsum += imos[i];
    A[i] += cumsum;
    int moved = min(A[i], N - 1 - i);
    // 区間を計算
    if (moved > 0) {
      imos[i + 1] += 1;
      imos[i + 1 + moved] += -1;
    }
    A[i] -= moved;
  }
  rep(i, N) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
}
