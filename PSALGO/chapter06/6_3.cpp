#include <iostream>
using namespace std;

int main() {
  cout << "Start Game" << "\n";

  int left = 20, right = 38;

  while(right - left > 1) {
    int mid = left + (right - left) / 2;

    cout << "Is the age less than " << mid << " ? (yes/no)" << "\n";

    string ans;
    cin >> ans;

    if (ans == "yes") right = mid;
    else left = mid;
  }
  cout << "The age is " << left << "!" << "\n";
}