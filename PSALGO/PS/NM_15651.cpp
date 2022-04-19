#include <iostream>
using namespace std;

int N, M;

int arr[8];

void solve(int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; ++i) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = 1; i <= N; ++i) {
    arr[cnt] = i;
    solve(cnt + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  solve(0);
}