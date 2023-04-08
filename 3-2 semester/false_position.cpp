#include<bits/stdc++.h>
using namespace std;

const double EPSILON = (double) 0.01;

double funVal(double x) {
  return x * x * x - x * x + 2;
}

void falsePosition(double a, double b) {
  if (funVal(a) * funVal(b) >= 0) {
    cout << "You have not assumed right a and b" << endl;
    return;
  }

  double c = a;
  while ((b - a) >= EPSILON) {
    c = ((a * funVal(b)) - b * (funVal(a))) / (funVal(b) - funVal(a));
    if (funVal(c) == 0.0) break;
    else if (funVal(c) * funVal(a) < 0) b = c;
    else a = c;
  }
  cout << "The value of root is : " << c << endl;;
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  double a, b;
  cin >> a >> b;
  falsePosition(a, b);
  return 0;
}
