#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int N;

bool is_valid_move(vector<vector<char>> &maze, vector<vector<bool>> &checked, int y, int x) {
  if (y < 0 || y > (N - 1) || x < 0 || x > (N - 1)) return false;
  if (checked.at(y).at(x)) return false;
  if (maze.at(y).at(x) == '#') return false;

  return true;
}

bool reachable(vector<vector<char>> &maze, vector<vector<bool>> &checked, int y, int x) {
  if (y == N - 1 && x == N - 1) {
    return true;
  }
  checked.at(y).at(x) = true;

  bool result = false;
  if (is_valid_move(maze, checked, y - 1, x) && reachable(maze, checked, y - 1, x)) {
    result = true;
  }
  if (is_valid_move(maze, checked, y, x - 1) && reachable(maze, checked, y, x - 1)) {
    result = true;
  }
  if (is_valid_move(maze, checked, y, x + 1) && reachable(maze, checked, y, x + 1)) {
    result = true;
  }
  if (is_valid_move(maze, checked, y + 1, x) && reachable(maze, checked, y + 1, x)) {
    result = true;
  }
  return result;
}

int main() {
  cin >> N;
  vector<vector<char>> maze(N, vector<char>(N));
  rep(i, N) rep(j, N) cin >> maze.at(i).at(j);

  vector<vector<bool>> checked(N, vector<bool>(N, false));
  if (reachable(maze, checked, 0, 0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
