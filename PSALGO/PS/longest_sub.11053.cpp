#include <iostream>
using namespace std;

#define MAX 1001

int arr[MAX];
int dp[MAX];
int result = -1;

int chmax(int a, int b) {
  return a > b ? a : b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  dp[0] = 0;
  
  for (int i = 1; i <= N; ++i) {
    dp[i] = 1;

    for (int j = 1; j < i; ++j) {
      if (arr[i] > arr[j]) {
        dp[i] = chmax(dp[i], dp[j] + 1);
      }
    }

    result = chmax(dp[i], result);
  }

  cout << result << "\n";
}