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


// |S| = N クエリQ個
// 整数Xiと文字Ciが与えられるのでSのXi番目の文字をCiに置き換える
// その後Sに文字列ABCが部分文字列として何箇所含まれるかを出力する
// N, Qは2 * 10^5
// A, B, Cの出現位置を取っておいて、insertしたり2分探索で前後探したりすれば良さそう？
// なんかTLEしそうではあるが…
// A = [0, 3, 5]
// B = [1, 4, 6]
// C = [2, 5, 7]
int main() {
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  set<int> A, B, C;

  int ans = 0;
  rep(i, S.size()) {
    if (S[i] == 'A') {
      A.insert(i);
    } else if (S[i] == 'B') {
      B.insert(i);
    } else if (S[i] == 'C') {
      C.insert(i);
    }
  }
  for(int i : A) {
    if (B.count(i + 1) && C.count(i + 2)) {
      ans++;
    }
  }

  while(Q--) {
    int Xi; char Ci;
    cin >> Xi >> Ci;
    Xi--;
    
    // 変わるとき、ABCがすでに成立していたら1個引く
    if (A.count(Xi)) {
      A.erase(Xi);
      if (B.count(Xi + 1) && C.count(Xi + 2)) {
        ans--;
      }
    } else if (B.count(Xi)) {
      B.erase(Xi);
      if (A.count(Xi - 1) && C.count(Xi + 1)) {
        ans--;
      }
    } else if (C.count(Xi)) {
      C.erase(Xi);
      if (A.count(Xi - 2) && B.count(Xi - 1)) {
        ans--;
      }
    }
    // A, B, Cに変わるときチェック
    if (Ci == 'A') {
      A.insert(Xi);
      if (B.count(Xi + 1) && C.count(Xi + 2)) {
        ans++;
      }
    } else if (Ci == 'B') {
      B.insert(Xi);
      if (A.count(Xi - 1) && C.count(Xi + 1)) {
        ans++;
      }
    } else if (Ci == 'C') {
      C.insert(Xi);
      if (A.count(Xi - 2) && B.count(Xi - 1)) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}

