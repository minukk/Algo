void serach(const Graph &G, int s) {
  int N = (int)G.size();

  vector<bool> seen(N, false);
  queue<int> todo;

  seen[s] = true;
  todo.push(s);

  while(!todo.empty()) {
    int v = todo.front();
    todo.pop();

    for (int x: G[v]) {
      if (seen[x]) continue;

      seen[x] = true;
      todo.push(x);
    }
  }
}