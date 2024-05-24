
#include <iostream>
#include <string>
using namespace std;

long long calculateExpressions(const string &S, int index, const string &current_expression, long long current_sum) {
  if (index == S.size()) {
    return current_sum += stoll(current_expression);
  }

  long long total = 0;
  total += calculateExpressions(S, index + 1, current_expression + S.at(index), current_sum);

  if (!current_expression.empty()) {
    total += calculateExpressions(S, index + 1, string(1, S.at(index)), current_sum + stoll(current_expression));
  }
  return total;
}

int main() {
  string S;
  cin >> S;
  
  cout << calculateExpressions(S, 1, string(1, S[0]), 0) << endl;
}
