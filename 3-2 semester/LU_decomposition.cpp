#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<vector<double>> matrix(n, vector<double>(n));
  vector<vector<double>> L(n, vector<double>(n, 0.0));
  vector<vector<double>> U(n, vector<double>(n, 0.0));
  vector<double> B, Y(n, 0.0), X(n, 0.0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (j == n) {
        double x; cin >> x;
        B.push_back(x);
        continue;
      }
      cin >> matrix[i][j];
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = k; i < n; ++i) {
      double sum = 0;
      for (int j = 0; j < n; ++j) {
        sum += (L[k][j] * U[j][i]);
      }
      U[k][i] = matrix[k][i] - sum;
    }
    for (int i = k; i < n; ++i) {
      if (i == k) {
        L[k][k] = 1;
        continue;
      }
      double sum = 0;
      for (int j = 0; j < n; ++j) {
        sum += L[i][j] * U[j][k];
      }
      L[i][k] = (matrix[i][k] - sum) / U[k][k];
    }
  }
  for (int i = 0; i < n; ++i) {
    double sum = 0.0;
    for (int j = 0; j < n; ++j) {
      sum += L[i][j] * Y[j];
    }
    Y[i] = B[i] - sum;
  }
  for (int i = n - 1; i >= 0; --i) {
    double sum = 0.0;
    for (int j = i + 1; j < n; ++j) {
      sum += U[i][j] * X[j];
    }
    X[i] = (Y[i] - sum) / U[i][i];
  }
  for (int i = 0; i < n; ++i) cout << "a" << i + 1 << " = " << X[i] << '\n';
  return 0;
}