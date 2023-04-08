#include <bits/stdc++.h>
using namespace std;

double f(double x) { return 3.0 * x - cos(x) - 1; }
double fPrime(double x) { return (double) 3.0 + sin(x); }

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    double x0;
    cin >> x0;
    int step = 1e6;
    double eps = 0.0;
    do {
      double x1 = x0 - (f(x0) / fPrime(x0));
      step--;
      if (!step) {
        cout << "Not convergence.\n";
        return 0;
      }
      eps = (x1 - x0) / x1;
      swap(x0, x1); 
    } while (eps > 0.05);
    cout << x0 << '\n';
  }
  return 0;
}
