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

int N, M;
vector<int> vec;
int rec(int idx, int to) {
  if (idx == N) return 0;
  // idxから最短距離を取る
  int res = 0, min_d = min(vec[idx], to);
  // もし最短距離が1ならそこで1を返して加算
  if (idx + 1 == min_d) {
    res += (1 + rec(idx + 1, vec[idx + 1]));
  } else if (idx + 1 < min_d) {
    // 探索続行
    res += rec(idx + 1, min_d);
  // なければ次のidxに進める
  }
  return res;
}

// 東西一列に並んだN個の島とN-1本の橋がある
// i番目の橋はi, i + 1の島を結ぶ
// M個の要望
// aiとbiの島を橋を渡って行き来できないようにしろ
// M個の要望をすべて叶えるために取り除く必要のある橋の本数をもとめよ
int main() {
  cin >> N >> M;
  vec.resize(N, INT_MAX);
  rep(i, M) {
    int ai, bi; cin >> ai >> bi;
    ai--, bi--;
    chmin(vec[ai], bi);
  }

  // 1. とりあえず最小範囲が大事
  // 2. 最小範囲が1になったら必ず切断
  // 3. 1 - 4のとき2, 3, 4 と見ていってminを取る、
  // 4. minが4より小さかったら更に
  // 再帰でみていく？
  int ans = rec(0, vec[0]);
  cout << ans << endl;
}

