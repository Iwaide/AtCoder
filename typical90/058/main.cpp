#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int calc(int n) {
  int a = 0, b = 0, c = 0, d = 0, e = 0;
  e = n % 10;
  d = n % 100 / 10;
  c = n % 1000 / 100;
  b = n % 10000 / 1000;
  a = n / 10000;
  return (n + a + b + c + d + e) % 100000;
}

int main() {
  int N; long long K;
  cin >> N >> K;
  vector<int> path;
  vector<int> vis(100000, -1);
  path.push_back(N);
  vis[N] = 0;
  rep2(i, 1, 100001) {
    N = calc(N);
    if (i == K) {
      cout << N << endl;
      return 0;
    }
    if (vis[N] >= 0) {
      break;
    } else {
      path.push_back(N);
      vis[N] = i;
    }
  }
  cout << path[(K - vis[N]) % (path.size() - vis[N]) + vis[N]] << endl;
}
