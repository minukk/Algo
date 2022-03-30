#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> H(N), S(N);
  
  for (int i = 0; i < N; ++i) {
    cin >> H[i] >> S[i];
  }

  long long M = 0;

  for (int i = 0; i < N; ++i) {
    M = max(M, H[i] + S[i] * N);
  }

  long long left = 0, right = M;

  while(right - left > 1) {
    long long mid = (left + right) / 2;

    bool ok = true;

    vector<long long> t(N, 0);

    for (int i = 0; i < N; ++i) {
      if (mid < H[i]) {
        ok = false;
      } else {
        t[i] = (mid - H[i]) / S[i];
      }
    }

    sort(t.begin(), t.end());

    for (int i = 0; i < N; ++i) {
      if (t[i] < i) {
        ok = false;
      }
    }
    
    if (ok) right = mid;
    else left = mid;
  }

  cout << right << "\n";
}
