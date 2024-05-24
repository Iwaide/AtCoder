  #include <bits/stdc++.h>
  using namespace std;
  #define rep(i, n) for (int i = 0; i < (int)(n); i++)
  #define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

  int H, W;

  bool is_valid_move(vector<vector<char>> &town, vector<vector<bool>> &checked, int y, int x) {
    if (y < 0 || y >= H || x < 0 || x >= W) return false;
    if (checked.at(y).at(x)) return false;
    if (town.at(y).at(x) == '#') return false;

    return true;
  }

  bool reachable(vector<vector<char>> &town, vector<vector<bool>> &checked, int y, int x) {
    if (town.at(y).at(x) == 'g') {
      return true;
    }

    checked.at(y).at(x) = true;

    bool result = false;
    if (is_valid_move(town, checked, y - 1, x) && reachable(town ,checked, y - 1, x)) {
      result = true;
    }
    if (is_valid_move(town, checked, y, x + 1) && reachable(town ,checked, y , x + 1)) {
      result = true;
    }
    if (is_valid_move(town, checked, y + 1, x) && reachable(town ,checked, y + 1, x)) {
      result = true;
    }
    if (is_valid_move(town, checked, y, x - 1) && reachable(town ,checked, y, x - 1)) {
      result = true;
    }
    return result;
  }

  int main() {
    cin >> H >> W;
    vector<vector<char>> town(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> town.at(i).at(j);

    vector<vector<bool>> checked(H, vector<bool>(W, false));
    int startY = -1, startX = -1;
    rep(i, H) {
      rep(j, W) {
        if (town.at(i).at(j) == 's') {
          startY = i;
          startX = j;
          break;
        }
      }
      if (startY >= 0 && startX >= 0) break;
    }
    if (reachable(town, checked, startY, startX)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
