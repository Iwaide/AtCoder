#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define all(a) (a).begin(), (a).end()
template<typename T>
void print_vector(vector<T> &vec) {
  rep(i, vec.size()) {
    if (i != vec.size() - 1) {
      cout << vec[i] << " ";
    } else {
      cout << vec[i] << endl;
    }
  }
}

// コンテストはA, B, C, D, E問題からなる
// 31人が参加し、全員が1問以上解いた
// 参加者の名前を取った点数が大きい方から順に出力せよ
// bit全探索で全部の点数と名前出して、mapに突っ込んでいけば良さそう
int main() {
  vector<int> questions(5);
  rep(i, 5) cin >> questions[i];

  map<int, set<string>> res;

  rep2(i, 1, (1 << 5)) {
    bitset<5> b(i);
    string S = "", T = "ABCDE";
    int score = 0;
    rep(j, 5) {
      if (b.test(j)) {
        score += questions[j];
        S += T[j];
      }
    }

    res[score].insert(S); 
  }
  vector<set<string>> ans;
  for(auto p : res) {
    set<string> ss;
    for(string s : p.second) {
      ss.insert(s);
    }
    ans.push_back(ss);
  }
  reverse(all(ans));
  for(auto s : ans) {
    for(auto si : s) {
      cout << si << endl;
    }
  }
}

