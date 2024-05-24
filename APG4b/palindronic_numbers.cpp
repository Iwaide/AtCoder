#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   int A, B;
//   cin >> A >> B;
//   int counter = 0;
//   rep2(i, A, B + 1) {
//     int x = i;
//     list<int> lst;
//     while(x) {
//       lst.push_back(x % 10);
//       x /= 10;
//     }
//     bool is_palindronic = true;
//     while(lst.size() > 1) {
//       int first = lst.front();
//       int back = lst.back();
//       lst.pop_front();
//       lst.pop_back();
//       if (first != back) {
//         is_palindronic = false;
//         break;
//       }
//     }
//     lst.clear();
//     if (is_palindronic) {
//       counter++;
//     }
//   }
//   cout << counter << endl;
// }


int main() {
  int A, B;
  cin >> A >> B;
  int counter = 0;
  rep2(i, A, B + 1) {
    bool is_palindronic = i / 10000 == i % 10 && i % 10000 / 1000 == i % 1000 / 100;
    if (is_palindronic)
      counter++;
  }
  cout << counter << endl;
}
