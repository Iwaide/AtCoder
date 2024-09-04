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

// int main() {
//   int N, X, Y;
//   cin >> N >> X >> Y;
//   X--; Y--;
//   map<int, set<int>> graph;
//   // X, Yに辺が張られている
//   graph[X].insert(Y); graph[Y].insert(X);

//   // 1..N-1についてiとi+1に辺が張られている
//   rep(i, N - 1) {
//     graph[i].insert(i+1);
//     graph[i+1].insert(i);
//   }

//   // 1..Nの頂点からそれぞれの頂点への距離を調べる
//   // vec[from頂点][to頂点] = 距離
//   vector<vector<int>> distance(N, vector<int>(N, -1));

//   rep(i, N) {
//     queue<int> q;
//     q.push(i);
//     // 距離0からスタート
//     distance[i][i] = 0;
//     while(!q.empty()) {

//       int z = q.front(); q.pop();
//       for(int p : graph[z]) {
//         if (distance[i][p] == -1) {
//           distance[i][p] = distance[i][z] + 1;
//           q.push(p);
//         }
//       }
//     }
//   }
//   // [距離] = 個数
//   vector<int> ans(N);
//   // (1, 2), (2, 1)を2重カウントしないようにする
//   for(int i = 0; i < N - 1; i++) {
//     for(int j = i + 1; j < N; j++) {
//       ans[distance[i][j]] += 1;
//     }
//   }

//   rep2(i, 1, N) cout << ans[i] << endl;
// }

int N, X, Y;
int ans[2010];
int main() {
    cin >> N >> X >> Y;
    X--; Y--;

    rep2(i, 0, N) rep2(j, i + 1, N) {
        int k = INT_MAX;

        // 直接iからjに向かう
        chmin(k, j - i);

        // iからXに行って、Yへ移動し、jに向かうケース
        chmin(k, abs(X - i) + abs(Y - j) + 1);

        ans[k]++;
    }

    rep2(k, 1, N) cout << ans[k] << endl;
}