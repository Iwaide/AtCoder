#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  rep(i, N) {
    long long Ai; cin >> Ai;
    Ai--;
    A[i] = Ai;
  }
  vector<long long> visited(N, -1);
  vector<long long> paths;
  long long current = 0;
  paths.push_back(current);
  visited[current] = 0;
  bool is_loop = false;

  for(long long i = 1; i <= K; i++) {
    current = A[current];
    if (visited[current] >= 0) {
      is_loop = true;
      break;
    } else {
      visited[current] = i;
      paths.push_back(current);
    }
  }
  if (is_loop) {
    // 初めてそこに行った回数
    long long index = visited[current];
    K -= index;
    vector<long long> sub_vector(paths.begin() + index, paths.end());
    long long mod = K % sub_vector.size();
    cout << ++sub_vector[mod] << endl;
  } else {
    cout << ++current << endl;
  }
}
