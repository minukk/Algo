#include <iostream>
#include <vector>
using namespace std;

int N, L;
int result;
vector<vector<int> > matrix(101, vector<int>(101));
bool visited[101];

void checkRow(int y) {
  int cur = matrix[y][0];
  
  for (int i = 0; i < N; ++i) {
    if (matrix[y][i] != cur) {
      if (!(abs(matrix[y][i] - cur) <= 1)) return;

      if (matrix[y][i] < cur) {
        int height = -1;

        for (int j = i; j < i + L; ++j) {
          if (!visited[j] && j < N) {
            visited[j] = true;
            if (height == -1) {
              height = matrix[y][j];
              continue;
            }
            if (height != -1 && matrix[y][j] != height) return;
          } else return;
        }
        i += L - 1;
        
        if (i >= N) break;
      } else {
        int height = -1;
        for (int j = i - 1; j > i - 1 - L; --j) {
          if (!visited[j] && j >= 0) {
            visited[j] = true;
            if (height == -1) {
              height = matrix[y][j];
              continue;
            }
            if (height != -1 && matrix[y][j] != height) return;
          } else return;
        }
      }
      cur = matrix[y][i];
    }
  }
  result++;
}

void checkCol(int x) {
  int cur = matrix[0][x];
  
  for (int i = 0; i < N; ++i) {
    if (matrix[i][x] != cur) {
      if (!(abs(matrix[i][x] - cur) <= 1)) return;
      if (matrix[i][x] < cur) {
        int height = -1;

        for (int j = i; j < i + L; ++j) {
          if (!visited[j] && j < N) {
            visited[j] = true;
            if (height == -1) {
              height = matrix[j][x];
              continue;
            }
            if (height != -1 && matrix[j][x] != height) return;
          } else return;
        }
        i += L - 1;
        
        if (i >= N) break;
      } else {
        int height = - 1;
        for (int j = i - 1; j > i - 1 - L; --j) {
          if (!visited[j] && j >= 0) {
            visited[j] = true;
            if (height == -1) {
              height = matrix[j][x];
              continue;
            }
            if (height != -1 && matrix[j][x] != height) return;
          } else return;
        }
      }
      cur = matrix[i][x];
    }
  }
  result++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L;

  for (int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j) 
      cin >> matrix[i][j];

  for (int i = 0; i < N; ++i) {
    memset(visited, false, sizeof(visited));
    checkRow(i);
  }

  for (int i = 0; i < N; ++i) {
    memset(visited, false, sizeof(visited));
    checkCol(i);
  }

  
  cout << result << "\n";
}