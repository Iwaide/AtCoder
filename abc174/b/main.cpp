#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  ll N, D;
  cin >> N >> D;
  vector<pair<ll, ll>> points;
  rep(i, N) {
    ll X, Y;
    cin >> X >> Y;
    points.push_back(make_pair(X, Y));
  }
  ll result = 0;
  for(auto point: points) {
    ll X = point.first;
    ll Y = point.second;
    if (D * D >= (X * X + Y * Y) ) result++;
  }
  cout << result << endl;
}
