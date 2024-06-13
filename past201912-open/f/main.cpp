#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// int main() {
//   string S;
//   cin >> S;
//   vector<string> words;
//   for(int i = 0; i < S.size(); ){
//     string word;
//     int capital_count = 0;
//     while(capital_count < 2) {
//       char c = S.at(i);
//       if (isupper(c)) {
//         capital_count++;
//         c = (char) c - ('A' - 'a');
//       }
//       word += c;
//       i++;
//     }
//     words.push_back(word);
//   }
//   sort(words.begin(), words.end());
//   for(auto word: words) {
//     for(int i = 0; i < word.size(); i++) {
//       char c = word.at(i);
//       if (i == 0 || i == (word.size() - 1)) {
//           c = (char) c + ('A' - 'a');
//       }
//       cout << c;
//     }
//   }
//   cout << endl;
// }

int main() {
  string S;
  cin >> S;
  vector<string> words;
  for(int i = 0; i < S.size(); ){
    int j = i + 1;
    while(j < S.size() && islower(S.at(j))) {
      j++;
    }
    string word = S.substr(i, j + 1 - i);
    word.at(0) = tolower(word.at(0));
    word.back() = tolower(word.back());
    words.push_back(word);
    i = j + 1;
  }
  sort(words.begin(), words.end());
  for(auto word: words) {
    word.at(0) = toupper(word.at(0));
    word.back() = toupper(word.back());
    cout << word;
  }
  cout << endl;
}
