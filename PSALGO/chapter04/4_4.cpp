#include <iostream>
using namespace std;

int GCD(int m, int n) {
  if (n == 0) return m;

  return GCD(n, m % n);
}

int main() {
  cout << GCD(51, 15) << "\n";
  cout << GCD(15, 51) << "\n";
}