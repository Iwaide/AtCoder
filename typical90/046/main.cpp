#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

void cin_vector(int N, map<int, int> &vec) {
  rep(i, N) {
    long long num;
    cin >> num;
    int modNum = num % 46;
    vec[modNum] += 1;
  }
}

int main() {
  int N;
  cin >> N;
  map<int, int> A;
  map<int, int> B;
  map<int, int> C;
  cin_vector(N, A);
  cin_vector(N, B);
  cin_vector(N, C);
  long long result = 0;
  for(auto a: A) {
    for (auto b: B) {
      for (auto c: C) {
        if ((a.first + b.first + c.first) % 46 == 0) {
          result += 1LL * a.second * b.second * c.second;
        }
      }
    }
  }
  cout << result << endl;
}

