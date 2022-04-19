#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321
int N, M;
vector<int> arr;
bool visited[8];
int result[8];

void solve(int idx) {
  if (idx == M) {
    for (int i = 0; i < M; ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (visited[i] == false) {
      visited[i] = true;
      result[idx] = arr[i];
      solve(idx + 1);
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  int temp;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());
  solve(0);
}