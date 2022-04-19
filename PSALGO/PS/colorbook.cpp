#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int countArea;
int maxArea;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
// vector<vector<int> > picture;
// vector<int> arr;
int arr[6][4] = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
bool visited[6][4];

void BFS(int n, int m) {
  int cnt = 1;
  int color = arr[n][m];
  queue<pair<int, int> > q;
  q.push(make_pair(n, m));
  visited[n][m] = true;

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nextY = y + dy[i];
      int nextX = x + dx[i];

      if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
        if (arr[nextY][nextX] == color && !visited[nextY][nextX]) {
          visited[nextY][nextX] = true;
          q.push(make_pair(nextY, nextX));
          cnt++;
        }
      }
    }
  }

  maxArea = max(maxArea, cnt);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  // int input;
  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j < M; ++j) {
  //     cin >> input;
  //     arr.push_back(input);
  //   }
  //   picture.push_back(arr);
  // }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (arr[i][j] != 0 && !visited[i][j]) {
        BFS(i, j);
        countArea++;
      }
    }
  }

  cout << countArea << " " << maxArea << "\n";
}