#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<int> result(7);

void solve(int idx) {
  if (idx == M) {
    for (int i = 0; i < M; ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; ++i) {
    result[idx] = arr[i];
    solve(idx + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  int input;
  for (int i = 0; i < N; ++i) {
    cin >> input;
    arr.push_back(input);
  }
  sort(arr.begin(), arr.end());
  solve(0);
}