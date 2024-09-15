#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 0-indexed に変換
        G[u].push_back(v);
    }

    int S, T;
    cin >> S >> T;
    S--; T--; // 0-indexed に変換

    // 距離を格納する3次元配列 (頂点 x 状態)
    vector<vector<int>> dist(N, vector<int>(3, INF));
    queue<pair<int, int>> q;

    // 初期状態を設定 (S, 0) スタートで距離は 0
    dist[S][0] = 0;
    q.push({S, 0});

    while (!q.empty()) {
        int v, mod;
        tie(v, mod) = q.front();  
        q.pop();

        int next_dist = dist[v][mod] + (mod == 2 ? 1 : 0); // 次のステップでけんけんぱが完了するなら+1

        for (int u : G[v]) {
            int next_mod = (mod + 1) % 3;
            if (dist[u][next_mod] == INF) {
                dist[u][next_mod] = next_dist;
                q.push({u, next_mod});
            }
        }
    }

    // T に状態 0 で到達できるかを確認
    int answer = dist[T][0];
    if (answer == INF) {
        cout << -1 << endl; // 到達できない場合
    } else {
        cout << answer << endl; // 最小回数
    }

    return 0;
}
