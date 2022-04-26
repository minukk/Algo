#include <iostream>
using namespace std;

int N;
int arr[200][200];
bool visited[200][200];

int result;
int dy[4] = {0, 0 , -1, 1};
int dx[4] = {-1, 1, 0, 0};

void solve(int y, int x) {
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (0 <= ny && ny < N && 0 <= nx && nx < N) {
      if (!visited[ny][nx] && arr[ny][nx] == 1) {
        visited[ny][nx] = true;
        solve(ny, nx);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!visited[i][j] && arr[i][j] == 1) {
        solve(i, j);
        result++;
      }
    }
  }

  cout << result << "\n";
}