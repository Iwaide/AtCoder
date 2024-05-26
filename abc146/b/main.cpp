#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   int N;
//   string S;
//   cin >> N >> S;
//   vector<char> alphabet = {
//     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
//     'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
//   };

//   rep(i, S.size()) {
//     int index = 0;
//     rep(j, alphabet.size()) {
//       if (S.at(i) == alphabet.at(j)) {
//         index = j;
//         break;
//       }
//     }
//     index += N;
//     if (index > 25) index -= 26;
//     S.at(i) = alphabet.at(index);
//   }
//   cout << S << endl;
// }

int main() {
  int N;
  string S;
  cin >> N >> S;
  rep(i, S.size()) {
    int index = (int) (S.at(i) - 'A');
    index = (index + N) % 26;
    S.at(i) = (char)(index + 'A');
  }
  cout << S << endl;
}
