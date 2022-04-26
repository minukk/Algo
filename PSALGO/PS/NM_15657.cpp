#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<bool> visited(8, false);
vector<int> result(8);

void solve(int idx) {
  if (idx == M) {
    for (int i = 0; i < M; ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (result[idx - 1] <= arr[i]) {
      result[idx] = arr[i];
      solve(idx + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
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