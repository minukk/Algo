#include <iostream>
using namespace std;

const int MAXNUM = 8;
int arr[MAXNUM];
int N, M;

void solve(int count) {
  if (count == M) {
    for (int i = 0; i < M; ++i) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 1; i <= N; ++i) {
    if (arr[count-1] <= i) {
      arr[count] = i;
      solve(count + 1);
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  solve(0);
}