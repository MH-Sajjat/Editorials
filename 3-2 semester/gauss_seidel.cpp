#include <bits/stdc++.h>
using namespace std;

double getX1(double x1, double x2, double x3) { return (1.0 - x2 * 3 + x3 * 5) / 12.0; }
double getX2(double x1, double x2, double x3) { return (28.0 - x1 - x3 * 3) / 5.0; }
double getX3(double x1, double x2, double x3) { return (76.0 - x1 * 3 - x2 * 7) / 13.0; }

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  double x1, x2, x3; cin >> x1 >> x2 >> x3;
  double err; cin >> err;
  while (true) {
    double temp1 = x1;
    double temp2 = x2;
    double temp3 = x3;
    x1 = getX1(x1, x2, x3);
    x2 = getX2(x1, x2, x3);
    x3 = getX3(x1, x2, x3);
    double err1 = fabs(((x1 - temp1) / x1) * 100.0);
    double err2 = fabs(((x2 - temp2) / x2) * 100.0);
    double err3 = fabs(((x3 - temp3) / x3) * 100.0);
    if (err1 <= err and err2 <= err and err3 <= err) break;
  }
  cout << fixed << setprecision(10);
  cout << "x1 = " << x1 << '\n';
  cout << "x2 = " << x2 << '\n';
  cout << "x3 = " << x3 << '\n';
  return 0;
}