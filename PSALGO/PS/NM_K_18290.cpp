#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int map[10][10];
bool visited[10][10];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int result = -987654321;
int sum;

bool isAdjacency(int y, int x) {
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (0 <= ny && ny < N && 0 <= nx && nx < M) {
      if (visited[ny][nx]) return false;
    }
  }
  return true;
}

void solve(int sum, int cnt) {
  if (cnt == K) {
    if (sum > result) result = sum;
    return;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (!visited[i][j] && isAdjacency(i, j)) {
        visited[i][j] = true;
        solve(sum + map[i][j], cnt + 1);
        visited[i][j] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;

  int a;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> map[i][j];
    }
  }

  solve(0, 0);

  cout << result << "\n";
}