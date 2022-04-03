#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calc_dist(double x1, double y1, double x2, double y2) {
  // 직각 삼각형의 가장 긴  변을 구하는 식
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  int N;
  cin >> N;

  vector<int> x(N), y(N);
  
  for (int i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
  }

  double min_dist = 987654321.0;

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

      if (dist_i_j < min_dist) {
        min_dist = dist_i_j;
      }
    }
  }

  cout << min_dist << "\n";
}