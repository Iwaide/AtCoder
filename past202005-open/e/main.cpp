#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

map<int, set<int>> G;
vector<int> c;

void insert_graph(int x, int y) {
  if (G.count(x)) {
    G[x].insert(y);
  } else {
    G.insert(make_pair(x, set<int> { y }));
  }
}

void operation1() {
  int x;
  cin >> x;
  x--;
  int color = c.at(x);
  cout << color << endl;
  if (!G.count(x)) return;
  for(int y : G.at(x)) {
    c.at(y) = color;
  }
}

void operation2() {
  int x;
  cin >> x;
  x--;
  cout << c.at(x) << endl;
  int color;
  cin >> color;
  c.at(x) = color;
}

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  rep(i, M) {
    int ui, vi;
    cin >> ui >> vi;
    ui--; vi--;
    insert_graph(ui, vi);
    insert_graph(vi, ui);
  }
  rep(i, N) {
    int ci;
    cin >> ci;
    c.push_back(ci);
  }
  rep(i, Q) {
    int operation;
    cin >> operation;

    if (operation == 1) {
      operation1();
    } else {
      operation2();
    }
  }
}

