#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  rep(i, N) cin >> A[i];
  map<int, long long> ans;
  rep(i, M) {
    int Ui, Vi;
    long long Bi;
    cin >> Ui >> Vi >> Bi;
    Ui--; Vi--;
    if(Ui == 0) {
      ans[Vi] = min(ans[Vi], Bi + A[Vi]); 
    } else if (Vi == 0) {
      ans[Ui] = min(ans[Ui], Bi + A[Ui]); 
    } else {
      
    }
  }
}

