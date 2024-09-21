#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 無限大を表す値
const int INF = 1<<29;

// 17 * 10 mod 7 = 170 mod 7 = 2
// 3 * 3 mod 7 = 2
// "12003212..." のように、数字を並べて行ったときに、その数字の和がなるべく小さくなるようにしつつ、
// Kで割ったあまりがちょうど 0 となるようにせよ
// これはわかる。dp[余り] = 各桁の和もまぁわかる
// * 10 はコスト0(各桁の和を増やさない)で、 + 1はコスト1(各桁の和を増やす)もわかる
// 余りを頂点とし、*10とか+1の操作を辺とする、ってそういうことか
int main() {
  int K;
  cin >> K;
  vector<int> dist(K, INF);
  // 0-1BFS用のque
  deque<int> que(2);

  dist[1] = 1;
  que.push_front(1);

  while(!que.empty()) {
    // 先端が0、末尾が1なので先端から取り出していく
    int v = que.front(); que.pop_front();

    // *10するとき
    int v2 = (v * 10) % K;
    if (dist[v2] > dist[v]) {
      dist[v2] = dist[v];
      que.push_front(v2);
    }

    // +1するとき
    v2 = (v + 1) % K;
    if (dist[v2] > dist[v]) {
      dist[v2] = dist[v] + 1;
      que.push_back(v2);
    }
  }

  cout << dist[0] << endl;
}
