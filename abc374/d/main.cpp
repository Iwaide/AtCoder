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

// xy平面に対し、レーザを照射しながら線分を印字する印字機がある
// 開始位置は(0, 0)
// 線分を印字するときは以下の流れに従う
// まずレーザ照射位置を線分の端点のうちどちらか1つに移動させる
// その後レーザ照射市のある端点からもう一方の端点までレーザを照射しながら一直線に移動させる
// レーザを照射していないとき速度S/秒
// レーザを照射しているとき照射位置はT/秒
// N本の線分を印字したい
// (Ai, Bi), (Ci, Di)を結ぶ
// 線分の照射の順番は入れ替えていいのか
// レーザー照射の時間は変わらないから、ヘッドをどう移動させるか、になる
// 貪欲っぽくやる？いやNの数は6だから全部計算すりゃいいか
// 端点の選び方も全探索する必要がありそう？
// 6! * 2 ^ 6ぐらい？まぁいけそう
int main() {
  int N; double S, T;
  cin >> N >> S >> T;
  vector<vector<int>> lines(N);
  rep(i, N) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    lines[i] = {A, B, C, D};
  }
  double ans = DBL_MAX;

  // 順番全探索用の配列を用意
  vector<int> v;
  rep(i, N) v.push_back(i);
  do {
    // 端点の選び方も全探索する
    rep(j, (1 << N)) {
      int x = 0, y = 0;
      double time = 0;
      bitset<6> b(j);
      rep(i, N) {
        auto line = lines[v[i]];
        double A = line[0], B = line[1], C = line[2], D = line[3];

        // testが1のときA, Bから始める、0のときC, Dから始める
        if (b.test(i)) {
          time += sqrt(abs(A - x) * abs(A - x) + abs(B - y) * abs(B - y)) / S;
          time += sqrt(abs(A - C) * abs(A - C) + abs(B - D) * abs(B - D)) / T;
          x = C; y = D;
        } else {
          time += sqrt(abs(C - x) * abs(C - x) + abs(D - y) * abs(D - y)) / S;
          time += sqrt(abs(A - C) * abs(A - C) + abs(B - D) * abs(B - D)) / T;
          x = A; y = B;
        }
      }
      chmin(ans, time);
    }
  } while(next_permutation(all(v)));
  cout << fixed << setprecision(20) << ans << endl;
}

