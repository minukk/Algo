#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

const long long INF = 1LL << 60;

long long rec(int i ) {
  if (i == 0) return 0;

  long long res = INF;

  chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

  if (i > 1) chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

  return res;
}

int main() {
  
}