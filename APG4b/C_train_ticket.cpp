#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
vector<char> expressions(3);

bool calculate_expressions(vector<int> &nums, int index, int current_sum) {
  if (index == 4) {
    if (current_sum == 7) {
      cout << nums.at(0) << expressions.at(0) << nums.at(1) << expressions.at(1) << nums.at(2) << expressions.at(2) << nums.at(3) << "=7" << endl;
      return true;
    } else {
      // expressions.pop_back();
      return false;
    }
  }
  // +のとき
  expressions.at(index - 1) = '+';
  if (calculate_expressions(nums, index + 1, current_sum + nums.at(index))) {
    return true;
  }
  // -のとき
  expressions.at(index - 1) = '-';
  if (calculate_expressions(nums, index + 1, current_sum - nums.at(index))) {
    return true;
  }

  return false;
}

int main() {
  string S;
  cin >> S;
  vector<int> nums = {
    (int) (S.at(0) - '0'), 
    (int) (S.at(1) - '0'), 
    (int) (S.at(2) - '0'), 
    (int) (S.at(3) - '0'), 
  };
  calculate_expressions(nums, 1, nums.at(0));
}
