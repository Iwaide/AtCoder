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

// 正しい鍵とダミーが混じったN本の鍵を持っている
// 鍵を何本でもさせるドアXがあり、正しい鍵をK本以上差し込むと開く
// M回のテストをした
// Ci本の鍵をドアに差し込む
// Ri = oなら開いた、xなら開かなかった
// どのテスト結果とも矛盾しない組み合わせの個数を求めよ
// Nは15なので普通にbit全探索で良さそう
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> A(M, vector<int>());
  vector<char> R(M);
  rep(i, M) {
    int Ci;
    cin >> Ci;
    rep(_, Ci) {
      int AiCj; cin >> AiCj;
      AiCj--;
      A[i].push_back(AiCj);
    }
    cin >> R[i];
  }

  int ans = 0;
  // bit全探索
  rep(i, (1 << N)) {
    bitset<15> b(i);
    bool can = true;
    rep(j, M) {
      int key_cnt = 0;
      for(auto k : A[j]) {
        if (b.test(k)) key_cnt++;
      }
      if ((key_cnt >= K && R[j] == 'x') || (key_cnt < K && R[j] == 'o')) {
        can = false;
        break;
      }
    }
    if (can) ans++;
  }
  cout << ans << endl;
}

