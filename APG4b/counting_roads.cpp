#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   int N, M;
//   cin >> N >> M;
//   vector<vector<int>> roads(M, vector<int>(2));
//   rep(i, M) {
//     int A, B;
//     cin >> A >> B;
//     roads.at(i).at(0) = A;
//     roads.at(i).at(1) = B;
//   }
//   rep(i, N) {
//     int counter = 0;
//     int city = i + 1;
//     rep(j, M) {
//       if (roads.at(j).at(0) == city || roads.at(j).at(1) == city) {
//         counter++;
//       }
//     }
//     cout << counter << endl;
//   }
// }

main() {
  int N, M;
  cin >> N >> M;
  vector<int> cities(N);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    cities.at(A - 1) += 1;
    cities.at(B - 1) += 1;
  }
  rep(i, N)
    cout << cities.at(i) << endl;
}
