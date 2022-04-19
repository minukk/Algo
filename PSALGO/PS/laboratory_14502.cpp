#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 8;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M;
int lab[MAX][MAX];
int temp[MAX][MAX];
int result;

void BFS() {
  int afterVirus[MAX][MAX];

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      afterVirus[i][j] = temp[i][j];
    }
  }

  queue<pair<int, int> > q;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (afterVirus[i][j] == 2) {
        q.push(make_pair(i, j));
      }
    }
  }

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nextY = y + dy[i];
      int nextX = x + dx[i];

      if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
        if (afterVirus[nextY][nextX] == 0) {
          afterVirus[nextY][nextX] = 2;
          q.push(make_pair(nextY, nextX));
        }
      }
    }
  }

  int empty = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (afterVirus[i][j] == 0) empty += 1;
    }
  }

  result = max(result, empty);
}

void makeWall(int count) {
  if (count == 3) {
    BFS();
    return;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (temp[i][j] == 0) {
        temp[i][j] = 1;
        makeWall(count + 1);
        temp[i][j] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> lab[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (lab[i][j] == 0) {
        for (int k = 0; k < N; ++k) {
          for (int l = 0; l < M; ++l) {
            temp[k][l] = lab[k][l];
          }
        }

        temp[i][j] = 1;
        makeWall(1);
        temp[i][j] = 0;
      }
    }
  }

  cout << result << "\n";
}