#include <iostream>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  char move;
  cin >> N;
  int map[N][N];
  int y = 1, x = 1;

  while (move != '0')
  {
    cin >> move;

    if (move == 'L')
    {
      y -= 1;
      if (y < 1)
        y = 1;
    }
    if (move == 'R')
    {
      y += 1;
      if (y > N + 1)
        y = N + 1;
    }
    if (move == 'U')
    {
      x -= 1;
      if (x < 1)
        x = 1;
    }
    if (move == 'D')
    {
      x += 1;
      if (x > N + 1)
        x = N + 1;
    }
  }
  cout << y << " " << x << '\n';
}