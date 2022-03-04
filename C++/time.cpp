#include <iostream>
#include <string>
using namespace std;

int n, result;

bool check(int h, int m, int s)
{
  if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
    return true;
  return false;
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int result = 0;

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < 60; j++)
    {
      for (int k = 0; k < 60; k++)
      {
        if (check(i, j, k))
          result++;
      }
    }
  }
  cout << result << '\n';
  return 0;
}