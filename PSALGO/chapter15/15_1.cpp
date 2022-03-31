#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
  vector<int> par, size;

  UnionFind(int n) : par(n, -1), size(n , 1) {}

  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (size[x] < size[y]) swap(x, y);

    par[y] = x;
    size[x] += size[y];
    return true;
  }

  int size(int x) {
    return size[root(x)];
  }
};

using Edge = pair<int, pair<int, int> >;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<Edge> edges(M);

  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = Edge(w, make_pair(u, v));
  }

  sort(edges.begin(), edges.end());

  long long res = 0;
  UnionFind uf(N);

  for (int i = 0; i <M; ++i) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (uf.issame(u, v)) continue;

    res += w;
    uf.unite(u, v);
  }
  cout << res << "\n";
}

