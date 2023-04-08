#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<vector<double>> matrix(n, vector<double>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      cin >> matrix[i][j];
    }
  }
  for (int k = 0; k < n; ++k) {
    int mx = abs(matrix[k][k]);
    int mxRow = k;
    for (int i = k + 1; i < n; ++i) {
      if (abs(matrix[i][k]) > mx) {
        mx = abs(matrix[i][k]);
        mxRow = i;
      }
    }
    swap(matrix[k], matrix[mxRow]);
    for (int i = k + 1; i < n; ++i) {
      double temp1 = matrix[k][k];
      double temp2 = matrix[i][k];
      for (int j = k; j <= n; ++j) {
        matrix[i][j] = matrix[k][j] - (matrix[i][j] / temp2) * temp1;
      }
    }
  }
  vector<double> ans(n, 0.0);
  for (int i = n - 1; i >= 0; --i) {
    double sum = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      sum += matrix[i][j] * ans[j];
    }
    ans[i] = (matrix[i][n] - sum) / matrix[i][i];
  }
  cout << fixed << setprecision(10);
  for (int i = 0; i < n; ++i) {
    cout << "a" << i + 1 << " = " << ans[i] << '\n';
  }
  return 0;
}