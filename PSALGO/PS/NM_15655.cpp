#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 8

int N, M;
vector<int> arr;
vector<int> result(MAX);


void solve(int idx) {
  if (idx == M) {
    for (int i = 0; i < M; ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (result[idx - 1] < arr[i]) {
      result[idx] = arr[i];
      solve(idx + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());

  solve(0);
}