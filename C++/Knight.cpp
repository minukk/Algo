#include <iostream>
#include <string>
using namespace std;

int map[8][8];
int result;
int y, x;
char column;
int dy[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dx[8] = {-2, 2, -2, 2, -1, 1, -1, 1};

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> column;
  int y = column - 'a';

  for (int i = 0; i < 8; i++)
  {
    int Y = y + dy[i];
    int X = x + dx[i];
    if (0 <= Y && Y < 8 && 0 <= X && X < 8)
      result++;
  }

  cout << result << '\n';
  return 0;
}