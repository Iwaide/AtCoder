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

// vector<vector<int>> vec;
// vector<int> seq;
// int N = 3;

// void rec(int i) {
//   if (i == 3) {
//     vec.push_back(seq);
//     return;
//   }
//   rep(j, 2) {
//     seq[i] = j;
//     rec(i+1);
//   }
// }
// int main() {
//   seq.resize(N);
//   rec(0);
//   for(auto v : vec) {
//     print_vector(v);
//   }
// }

int N = 3;

void rec(vector<int> &A) {
  if (A.size() == N) {
    print_vector(A);
    return;
  }
  rep(i, 2) {
    A.push_back(i);
    rec(A);
    A.pop_back();
  }
}

int main() {
  vector<int> A;
  rec(A);
}