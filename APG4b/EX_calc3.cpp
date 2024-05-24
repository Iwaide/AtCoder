#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define _GLIBCXX_DEBUG


map<string, int> int_scope;
map<string, vector<int>> vector_scope;

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

vector<int> interpret_vec_formula2(vector<int> result) {
  string lexical;
  cin >> lexical;
  if (lexical == "]") return result;
  if (lexical == ",") return interpret_vec_formula2(result);

  // 数字か変数
  result.push_back(get_int(lexical));
  return interpret_vec_formula2(result);
}

vector<int> interpret_vec_formula(int operation, vector<int> result) {
  string lexical;
  cin >> lexical;
  if (lexical == ";") return result;

  if (lexical == "[") {
    vector<int> new_vec = interpret_vec_formula2({});
    if (operation == 0) return interpret_vec_formula(0, new_vec);

    rep(i, result.size()) result.at(i) += operation * new_vec.at(i);
    return interpret_vec_formula(0, result);
  } else if (lexical == "+") {
    return interpret_vec_formula(1, result);
  } else if (lexical == "-") {
    return interpret_vec_formula(-1, result);
  } else if (vector_scope.count(lexical)) {
    vector<int> new_vec = vector_scope.at(lexical);
    if (operation == 0) return interpret_vec_formula(0, new_vec);

    rep(i, result.size()) result.at(i) += operation * new_vec.at(i);
    return interpret_vec_formula(0, result);
  }
}

int main() {
  int N;
  cin >> N;
  rep(i, N) {
    string tmp;
    cin >> tmp;
    if (tmp == "print_int") {
      // 最初の項
      cin >> tmp;
      int result = interpret_int_formula(0, get_int(tmp));
      cout << result << endl;
    }
    if (tmp == "int") {
      // 変数名
      string var_name;
      cin >> var_name;
      // = 捨てる
      cin >> tmp;
      cin >> tmp;
      int_scope[var_name] = interpret_int_formula(0, get_int(tmp));
    }
    if (tmp == "print_vec") {
      vector<int> result = interpret_vec_formula(0, {});
      cout << "[";
      rep(i, result.size()) {
        cout << " " << result.at(i);
      }
      cout << " " << "]" << endl;
    }
    if (tmp == "vec") {
      string var_name;
      cin >> var_name;
      // = 捨てる
      cin >> tmp;
      vector<int> result = interpret_vec_formula(0, {});
      vector_scope[var_name] = result;
    }
  }
}
