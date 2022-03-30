#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, v;
  cin >> N >> v;

  vector<int> a(N);

  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  bool exist = false;
  for (int i = 0; i < N; ++i) {
    if (a[i] == N) {
      exist = true;
    }
  }

  if (exist) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}