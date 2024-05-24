#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

void increment_num(int);

map<int, int> result;
int main() {
  int N;
  cin >> N;
  rep(i, N) {
    int num;
    cin >> num;
    increment_num(num);
    increment_num(num + 1);
    increment_num(num - 1);
  }
  int maximum = 0;
  for (const auto& [key, value] : result){
    maximum = max(maximum, value);
  }
  cout << maximum << endl;
}

void increment_num(int num) {
  if(result.count(num)) {
    result.at(num) += 1;
  } else {
    result.insert(make_pair(num, 1));
  }
  return;
}