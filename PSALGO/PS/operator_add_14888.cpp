#include <iostream>
#include <vector>
using namespace std;

#define MAX 12
int N;
int oper[MAX];
int operators[4];
int maxNum = -987654321;
int minNum = 987654321;

void solve(int result, int cnt) {
  if (cnt == N) {
    if (result > maxNum) maxNum = result;
    if (result < minNum) minNum = result;
    return;
  }

  for (int i = 0; i < 4; ++i) {
    if (operators[i] > 0) {
      operators[i]--;
      if (i == 0) solve(result + oper[cnt], cnt + 1);
      if (i == 1) solve(result - oper[cnt], cnt + 1);
      if (i == 2) solve(result * oper[cnt], cnt + 1);
      if (i == 3) solve(result / oper[cnt], cnt + 1);
      operators[i]++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  
  for(int i = 0; i < N; ++i) {
    cin >> oper[i];
  }

  for (int i = 0; i < 4; ++i) {
    cin >> operators[i];
  }

  solve(oper[0], 1);

  cout << maxNum << "\n";
  cout << minNum << "\n";
}