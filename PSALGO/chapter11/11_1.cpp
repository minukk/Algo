int root(int x) {
  if (par[x] == -1) return x;
  else return root(par[x]);
}

int root(int x) {
  if (par[x] == -1) return x;
  else return par[x] = root(par[x]);
}