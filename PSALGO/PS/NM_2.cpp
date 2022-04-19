#include <iostream>
#include <vector>
using namespace std;

int N, M;

int sol[8];

void solve(int idx) {
  if (idx == M) {
    for (int i = 0; i < M; ++i) {
      cout << sol[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = idx == 0 ? 1 : sol[idx - 1] + 1; i <= N; ++i) {
    sol[idx] = i;
    solve(idx + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  solve(0);
}