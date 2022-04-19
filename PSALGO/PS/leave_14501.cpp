#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int> > counsel;

int dp[20];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  counsel.push_back(make_pair(0, 0));

  for (int i = 1; i <= N; ++i) {
    int a, b;
    cin >> a >> b;
    counsel.push_back(make_pair(a, b));
  }

  int result = 0;

  for (int i = 1; i <= N + 1; ++i) {
    for (int j = 1; j < i; ++j) {
      dp[i] = max(dp[i], dp[j]);

      if (j + counsel[j].first == i) {
        dp[i] = max(dp[i], dp[j] + counsel[j].second);
      }
    }
    result = max(result, dp[i]);
  }
  
  cout << result << "\n";
}