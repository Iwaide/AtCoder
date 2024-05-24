#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int K;
  string A, B;
  cin >> K >> A >> B;
  long long KA = 0 , KB = 0;
  int tmp = K;
  while(A.size() > 0) {
    int tmp = stoi(A.substr(0, 1));
    A.erase(0, 1);
    KA = KA * K + tmp;
  }
  while(B.size() > 0) {
    int tmp = stoi(B.substr(0, 1));
    B.erase(0, 1);
    KB = KB * K + tmp;
  }
  // cout << KA << ":" << KB << endl;
  cout << (KA * KB);
}

