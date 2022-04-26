#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define MAX 101

int arr[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int Turn_Direction(int d, char c) {
  if (c == 'L')
  {
      if (d == 0) return 3;
      else if (d == 1) return 0;
      else if (d == 2) return 1;
      else if (d == 3) return 2;
  }
  else if (c == 'D')
  {
      if (d == 0) return 1;
      else if (d == 1) return 2;
      else if (d == 2) return 3;
      else if (d == 3) return 0;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  int appleY, appleX;
  for (int i = 0; i < K; ++i) {
    cin >> appleY >> appleX;
    arr[appleY - 1][appleX - 1] = 1;
  }

  int L, X;
  char C;
  cin >> L;

  vector<pair <int, char> > snake_dir;
  for (int i = 0; i < L; ++i) {
    cin >> X >> C;
    snake_dir.push_back(make_pair(X, C));
  }

  int second = 0;
  
  deque<pair<int, int> > Q;
  int x = 0;
  int y = 0;
  int d = 0;
  int idx = 0;
  Q.push_back(make_pair(y, x));
  arr[y][x] = 2;

  while(true) {
    second++;
    int ny = y + dy[d];
    int nx = x + dx[d];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[ny][nx] == 2) break;
    else if (arr[ny][nx] == 0) {
      arr[ny][nx] = 2;
      arr[Q.back().first][Q.back().second] = 0;
      Q.pop_back();
      Q.push_front(make_pair(ny, nx));
    }
    else if (arr[ny][nx] == 1) {
      arr[ny][nx] = 2;
      Q.push_front(make_pair(ny, nx));
    }

    if (idx < snake_dir.size()) {
      if (second == snake_dir[idx].first) {
        if (snake_dir[idx].second == 'L') d = Turn_Direction(d, 'L');
        else if (snake_dir[idx].second == 'D') d = Turn_Direction(d, 'D');
        idx++;
      }
    }
    y = ny;
    x = nx;
  }
  cout << second << "\n";
}