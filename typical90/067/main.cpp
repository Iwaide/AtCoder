#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

unsigned long long fromEight(unsigned long long result, string S) {
  if (S.size() == 0) {
    return result;
  }
  int tmp = stoi(S.substr(0, 1));
  S.erase(0, 1);
  return fromEight(result * 8 + tmp, S);
}

string toDigit(unsigned long long A, int B) {
  string S = "";
  if (A == 0) return "0";

  while(A > 0) {
    int remain = A % B;
    S = to_string(remain) + S;
    A /= B;
  }
  return S;
}

int main() {
  string N;
  int K;
  cin >> N >> K;
  rep(i, K) {
    // 8進数から10進数へ
    unsigned long long tmp = fromEight(0, N);
    // 10進数から9進数へ
    string S = toDigit(tmp, 9);
    // 8を5に置換して再代入
    N = regex_replace(S, regex("8"), "5");
  }
  cout << N << endl;
}

