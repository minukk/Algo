#include <iostream>
#include <vector>
using namespace std;

const vector<int> value = {500, 100, 50, 10};

int main() {
  int X;
  cin >> X;

  vector<int> a(4);
  
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }

  int result = 0;

  for (int i = 0; i < 4; ++i) {
    int add = X / value[i];

    if (add > a[i]) {
      add = a[i];
    }
    X -= value[i] * add;
    result += add;
  }

  cout << result << "\n";
}