#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[10];
bool visit[10];

void func(int start) {
  if (start == M) {
    for (int i = 0; i < M; ++i) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 1; i <= N; ++i) {
    if (!visit[i]) {
      arr[start] = i;
      visit[i] = true;
      func(start + 1);
      visit[i] = false;
    }
  }
}

int main() {
  cin >> N >> M;

  func(0);
}