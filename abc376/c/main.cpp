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

// Aiの大きさの1~NのおもちゃとBiの大きさの1~N-1の箱がある
// 大きさxの箱を1つ購入する
// N個のおもちゃそれぞれをN個の箱いずれかに入れる
// 箱に入るおもちゃは大きさ以下まで
// 可能な限り小さな箱を購入したい
// 大きいやつから入れていって、最後にあまったやつ？
int main() {
  int N; cin >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N - 1) cin >> B[i];

  sort(all(A), greater<int>());
  sort(all(B), greater<int>());

  int ans = 0;
  int can = true;
  int j = 0;
  rep(i, N) {
    int Ai = A[i];
    if (B[j] >= A[i]) {
      j++;
      continue;
    } else {
      if (can) {
        ans = Ai;
        can = false;
      } else {
        ans = -1;
        break;
      }
    }
  }
  cout << ans << endl;
}

