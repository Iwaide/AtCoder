#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

map<int, vector<int>> paths{
  { 0, { 0 } },
  { 1, { 1 } },
  { 2, { 2, 4, 8, 6 } },
  { 3, { 3, 9, 7, 1 } },
  { 4, { 4, 6 } },
  { 5, { 5 } },
  { 6, { 6 } },
  { 7, { 7, 9, 3, 1 } },
  { 8, { 8, 4, 2, 6 } },
  { 9, { 9, 1 } },
};

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  // Bの下位1桁
  int modB = B % 10;
  // B^Cしたときの下位1桁
  vector<int> pathB = paths[modB];
  int bc = pathB[C % pathB.size()];

  int modA = A % 10;
  vector<int> pathA = paths[modA];
  cout << pathA[bc % pathB.size()] << endl;;
}

