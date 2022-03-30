#include <iostream>
using namespace std;

int fibo(int N) {
  cout << "fibo(" << N << ") 호출" << "\n";

  if (N == 0) return 0;
  else if (N == 1) return 1;

  int result = fibo(N - 1) + fibo(N - 2);
  cout << N << " 번째 = " << result << "\n";

  return result;
}

int main() {
  fibo(10);
}