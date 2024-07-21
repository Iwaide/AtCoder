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

struct UnionFind {
  vector<int> points, rank, size;

  UnionFind(int n) {
    points.resize(n, -1);
    rank.resize(n, 1);
    size.resize(n, 1);
  }

  int find(int x) {
    if (points[x] == -1) return x;
    return points[x] = find(points[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
      swap(x, y);
    }
    if (rank[x] == rank[y]) {
      rank[y]++;
    }
    points[x] = y;
    size[y] += size[x];
  }

  int length(int x) {
    return size[find(x)];
  }
};
