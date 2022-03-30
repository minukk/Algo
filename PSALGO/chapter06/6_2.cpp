#include <iostream>
using namespace std;

// x가 조건을 만족하는지 여부
bool p(int x) {

}

int binary_search() {
  int left, right;

  while(right - left > 1) {
    int mid = left + (right - left) / 2;

    if (p(mid)) right = mid;
    else left = mid;
  }
  return right;
}