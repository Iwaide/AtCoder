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

// 刀N本持っていて2通りの攻撃ができる
// 持っている刀のうち1本を振る。魔物はaiポイントのダメージを受ける、何度でも振れる
// 投げつける、biポイントのダメージ、刀を失う
// Hポイント以上になると消滅する、最小で何回の攻撃が必要か
// N <= 10^5
// H <= 10^9
int main() {
  int N, H;
  cin >> N >> H;
  // 振れるだけ振ってから投げればいいわけだから
  // 振れるやつの中で一番高いやつと同じになるまで投げて残りを振りで埋めればいい気がする

  vector<int> a(N), b(N);
  int maxA = 0;
  rep(i, N) {
    int ai, bi; cin >> ai >> bi;
    chmax(maxA, ai);
    a[i] = ai, b[i] = bi;
  }

  // 振りの最大値まで投げる
  sort(all(b), greater<int>());
  int i = 0;
  int ans = 0;
  while(H > 0 && i < N && b[i] > maxA) {
    H -= b[i];
    ans++;
    i++;
  }
  if (H <= 0) {
    cout << ans << endl;
    return 0;
  } else {
    cout << ans + ((H + (maxA - 1)) / maxA) << endl;
  }
}

