#include <iostream>
#include <string>
using namespace std;

int n;
string plans;
int y = 1, x = 1;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
char moveTypes[4] = {'L', 'R', 'U', 'D'};

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  getline(cin, plans);

  for (int i = 0; i < plans.size(); i++)
  {
    char plan = plans[i];
    int ny = -1, nx = -1;
    for (int j = 0; j < 4; j++)
    {
      if (plan == moveTypes[j])
      {
        ny = y + dy[j];
        nx = x + dx[j];
      }
    }
    if (ny < 1 || nx < 1 || nx > n || nx > n)
      continue;
    x = nx;
    y = ny;
  }
  cout << y << ' ' << x << '\n';
  return 0;
}