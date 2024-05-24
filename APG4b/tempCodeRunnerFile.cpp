#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define _GLIBCXX_DEBUG


map<string, int> int_scope;

int get_int(string key) {
  if (int_scope.count(key)) {
    return int_scope.at(key);
  } else {
    return stoi(key);
  }
}

int interpret_int_formula(int operation, int result) {
  string lexical;
  cin >> lexical;
  if (lexical == ";") return result;

  if (lexical == "+") {
    return interpret_int_formula(1, result);
  } else if (lexical == "-") {
    return interpret_int_formula(-1, result);
  } else {
    int tmp = get_int(lexical);
    return interpret_int_formula(0, result += operation * tmp);
  }
}

int main() {
  int N;
  cin >> N;

  string tmp;
  cin >> tmp;
  if (tmp == "print_int") {
    // "="
    cin >> tmp;
    // 最初の項
    cin >> tmp;
    int result = interpret_int_formula(0, get_int(tmp));
    cout << result << endl;
  }
}
