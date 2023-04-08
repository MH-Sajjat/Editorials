#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  double sumOfX = 0.0;
  double sumOfY = 0.0;
  double sumOfXY = 0.0;
  double sumOfX2 = 0.0;
  for (int i = 0; i < n; ++i) {
    double x, y; cin >> x >> y;
    sumOfX += x;
    sumOfY += y;
    sumOfXY += (x * y);
    sumOfX2 += (x * x);
  }
  double m = (sumOfXY * n - sumOfX * sumOfY) / (sumOfX2 * n - sumOfX * sumOfX);
  double c = (sumOfX2 * sumOfY - sumOfX * sumOfXY) / (sumOfX2 * n - sumOfX * sumOfX);
  cout << fixed << setprecision(10);
  cout << "Equation of curve is " << "y = " << m << "x + " << c << '\n';
  return 0;
}