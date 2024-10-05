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

// 2つのグループに分けて昼休みの時間帯を分ける
// N個の部署が存在し、i番目の部署に所属する人数はKi人
// それぞれの部署をグループA,Bのいずれかに割当、グループごとに同時に昼休みをとり、
// かつグループA,Bの昼休みの時間が重ならないようにしたとき、
// 同時に昼休みをとる最大人数としてあり得る最小の値？
// まぁ普通にbit全探索でいいんだろうけど
int main() {
  int N; cin >> N;
  vector<int> K(N);
  rep(i, N) cin >> K[i];
  int ans = INT_MAX;
  rep(i, (1 << N)) {
    int A = 0, B = 0;
    bitset<20> b(i);
    rep(j, N) {
      // bitが1のときAに所属
      if (b.test(j)) {
        A += K[j];
      } else {
        B += K[j];
      }
    }
    chmin(ans, max(A, B));
  }
  cout << ans << endl;
}

