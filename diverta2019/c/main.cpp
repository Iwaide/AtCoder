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

// すぬけくんはN個の文字列を持っており、i番目はsiです
// これらの文字列を好きな順序でならべたあと、連結して1つの文字列を作る
// 作った文字列にABという部分文字列が含まれる個数としてありうる値のうち最大値を求めよ
int main() {
  int N; cin >> N;
  // そもそもsiにABが入ってるときはつなげても変化ないのでそのまま足す
  // Bから始まってるやつとAで終わってるやつをペアにすると+1される
  // 1. Bから始まってA以外で終わるやつ
  // 2. Aで終わってB以外から始まる
  // 3. Bで始まってAで終わる
  // 3が0のとき、1,2で1ペア作ってカウント+1して終わり
  // 3が1以上で、1, 2ペアのどちらかが余ったとき、
  // 3を数珠つなぎにしてどっちかにくっつける、が一番多い？

  vector<string> S(N);
  int ans = 0, firstB = 0, lastA = 0, both = 0;
  rep(i, N) {
    cin >> S[i];
    if (S[i][0] == 'B' && S[i].back() == 'A') {
      both++;
    } else if (S[i][0] == 'B') {
      firstB++;
    } else if (S[i].back() == 'A') {
      lastA++;
    }
    for(int j = 0; j < S[i].size() - 1;j++) {
      if(S[i][j] == 'A' && S[i][j + 1] == 'B') {
        ans++;
      }
    }
  }

  if (both == 0) {
    cout << ans + min(firstB, lastA) << endl;
  } else if (firstB == 0 && lastA == 0){
    cout << ans + (both - 1) << endl;
  } else {
    ans += min(firstB, lastA);
    if (firstB != lastA) {
      cout << ans + both << endl;
    } else {
      if (firstB > 0 && lastA > 0) {
        cout << ans + both << endl;
      } else {
        cout << ans + both - 1 << endl;
      }
    }
  }
}

