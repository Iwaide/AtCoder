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

bool is_insertable(string s, string t) {
  bool can = true;
  int j = 0;
  for(int i = 0; i < s.size(); i++) {
    if (s[i] == t[j]) {
      j++;
      continue;
    }
    j++;
    if (s[i] != t[j]) {
      can = false;
      break;
    }
  }
  return can;
}

// 文字列Sに対して以下の操作を0回移譲1回以下行って文字列Tと一致させられるか判定せよ
// S中の任意の位置に任意の文字を1つ挿入する
// S中の文字を1つ選び削除する
// S中の文字を1つ選び別の文字に変更する
// 長さを揃えてやって
int main() {
  int K; cin >> K;
  string S, T; cin >> S >> T;
  bool result = false;
  // S中の任意の位置に任意の文字を1つ挿入する
  if (S.size() == T.size() - 1) {
    result |= is_insertable(S, T);
  }

  // S中の文字を1つ選び削除する
  if (S.size() == T.size() + 1) {
    swap(S, T);
    result |= is_insertable(S, T);
  }

  // S中の文字を1つ選び別の文字に変更する
  if (S.size() == T.size()) {
    int dif_cnt = 0;
    for(int i = 0; i < S.size(); i++) {
      if (S[i] != T[i]) dif_cnt++;
    }
    if (dif_cnt <= 1) {
      result |= true;
    }
  }
  if (result) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

