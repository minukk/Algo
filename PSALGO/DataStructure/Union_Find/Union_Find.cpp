#include <iostream>
#include <vector>
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

int main() {

}