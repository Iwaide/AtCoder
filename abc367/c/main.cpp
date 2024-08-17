#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
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

// カスみたいな解き方
int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> R(N);
  rep(i, N) cin >> R[i];
  set<vector<int>> kouho;
  rep2(a, 1, 6) {

    rep2(b, 1, 6) {
      rep2(c, 1, 6) {
        rep2(d, 1, 6) {
          rep2(e, 1, 6) {
            rep2(f, 1, 6) {
              rep2(g, 1, 6) {
                rep2(h, 1, 6) {
                  vector<int> tmp;
                  tmp.push_back(a);
                  if (N > 1) tmp.push_back(b);
                  if (N > 2) tmp.push_back(c);
                  if (N > 3) tmp.push_back(d);
                  if (N > 4) tmp.push_back(e);
                  if (N > 5) tmp.push_back(f);
                  if (N > 6) tmp.push_back(g);
                  if (N > 7) tmp.push_back(h);
                  kouho.insert(tmp);
                }
              }
            }
          }
        }
      }
    }
  }
  
  for(vector<int> tmp : kouho) {
    bool can = true;
    int sum = 0;
    rep(i, tmp.size()) {
      if (tmp[i] > R[i]) {
        can = false;
        break;
      }
      sum += tmp[i];
    }
    if (can && sum % K == 0) {
      print_vector(tmp);
    }
  }
}
