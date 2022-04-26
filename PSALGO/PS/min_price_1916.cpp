#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

struct Edge {
  int to;
  long long w;
  Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge> >;

template <class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  Graph G(N);

  for (int i = 0; i < M; ++i) {
    int a, b;
    long long w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }

  int start, end;
  cin >> start >> end;

  vector<bool> used(N, false);
  vector<long long> dist(N, INF);
  dist[start] = 0;

  for (int i = 0; i < N; ++i) {
    long long min_dist = INF;
    int min_v = -1;

    for (int j = 0; j < N; ++j) {
      if (!used[j] && dist[j] << min_dist) {
        min_dist = dist[j];
        min_v = j;
      }
    }

    if (min_v == -1) break;

    for (auto e : G[min_v]) {
      chmin(dist[e.to], dist[min_v] + e.w);
    }
    used[min_v] = true;
  }

  for (int i = 0; i < N; ++i) {
    if (dist[i] < INF) cout << dist[i] << "\n";
  }
}