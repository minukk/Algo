#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int fibo(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  if (memo[n] != -1) return memo[n];

  return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
  int N;
  cin >> N;

  memo.assign(N, -1);
  fibo(N);
}