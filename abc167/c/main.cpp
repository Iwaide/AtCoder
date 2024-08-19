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

int N, M, X;
vector<vector<int>> A;
vector<int> C;

int achieve(vector<bool> &B) {
  vector<int> Algo(M, 0);
  int total = 0;
  rep(i, N) {
    if (B[i]) {
      vector<int> a = A[i];
      total += C[i];
      rep(j, M) {
        Algo[j] += a[j];
      }
    }
  }
  bool can = true;
  rep(i, M) {
    if (Algo[i] < X) {
      can = false;
      break;
    }
  }
  if (can) {
    return total;
  } else {
    return -1;
  }
}

vector<bool> B;
int rec(int index) {
  if (index == N) {
    int ans = achieve(B);
    if (ans == -1) {
      return INT_MAX;
    } else {
      return ans;
    }
  }

  B[index] = true;
  int ans1 = rec(index+1);
  B[index] = false;
  int ans2 = rec(index+1);
  return min(ans1, ans2);
}

int main() {
  cin >> N >> M >> X;
  A = vector<vector<int>>(N, vector<int>(M));
  C.resize(N);
  rep(i, N) {
    cin >> C[i];
    rep(j, M) cin >> A[i][j];
  }
  vector<bool> all = vector<bool>(N, true);
  int ans1 = achieve(all);

  if (ans1 == -1) {
    cout << "-1" << endl;
    return 0;
  }
  B.resize(N);
  int ans = rec(0);
  cout << ans << endl;
}