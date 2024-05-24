#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int max_tall = max(A, max(B, C));
  int min_tall = min(A, min(B, C));
  
  cout << max_tall - min_tall << endl;
}
