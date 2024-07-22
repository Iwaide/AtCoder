#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long A, B;
  cin >> A >> B;
  bitset<64> ans(A);
  if (A % 2 == 0) {
    long long diff = B - A;
    int mod = diff % 4;
    ans = B - mod;
    if (mod > 0) {
      for(long long i = B - mod + 1; i <= B; i++) {
        bitset<64> bi(i);
        ans ^= bi;
      }
    }
  } else {
    long long diff = B - A;
    int mod = diff % 4;
    ans = A;
    if (mod > 0) {
      for(long long i = B - mod + 1; i <= B; i++) {
        bitset<64> bi(i);
        ans ^= bi;
      }
    }
  }
  cout << ans.to_ulong() << endl;

  // cout << A << " ";
  // cout << ans.to_ulong() << endl;
  // rep2(i, A + 1, B + 1) {
  //   bitset<32> Ai(i);
  //   ans ^= Ai;
  //   cout << Ai.to_ulong() << " ";
  //   cout << ans.to_ulong() << endl;
  // }
  // cout << ans.to_ullong() << endl;
}

