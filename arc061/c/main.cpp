#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  int N = S.length();
  long long result = 0;
  rep(i, (1 << (N - 1))) {
    bitset<10> s(i);
    long long sum = 0;
    long long tmp = S.at(0) - '0';
    rep(j, N - 1) {
      if (s.test(j)) {
        sum += tmp;
        tmp = 0;
      }
      tmp = tmp * 10 + (S.at(j + 1) - '0');
    }
    sum += tmp;
    result += sum;
  }
  cout << result << endl;
}

// typedef long long ll;
// string S;
// int N;
// //-----------------------------------------------------------------
// int main() {
// 	cin >> S;
// 	N = S.length();
	
// 	ll ans = 0;
// 	rep2(i, 0, 1 << (N - 1)) {
// 		ll sm = 0;
// 		ll a = S[0] - '0';
// 		rep2(j, 0, N - 1) {
// 			if (i & (1 << j)) {
// 				sm += a;
// 				a = 0;
// 			}
// 			a = a * 10 + S[j + 1] - '0';
// 		}
// 		sm += a;
// 		ans += sm;
// 	}
// 	cout << ans << endl;
// }
