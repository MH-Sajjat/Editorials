#include <bits/stdc++.h>
using namespace std;

int getMax(int ar[], int n) {
    int mx = ar[0];
    for (int i = 0; i < n; ++i) {
        mx = max(mx, ar[i]);
    }
    return mx;
}

void countingSort(int ar[], int n, int exp) {
    vector<int> cnt[10];
    for (int i = 0; i < n; ++i) {
        cnt[(ar[i] / exp) % 10].push_back(ar[i]);
    }
    int pos = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cnt[i].size(); ++j) {
            ar[pos++] = cnt[i][j];
        }
    }
}

void radixSort(int ar[], int n) {
    int mx = getMax(ar, n);
    for (int exp = 1; (mx / exp) > 0; exp *= 10) {
        countingSort(ar, n, exp);
    }
}

int main() {
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    int ar[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) cin >> ar[i];

    radixSort(ar, n);
    cout << "Sorted array:";
    for (int i = 0; i < n; ++i) cout << " " << ar[i];
    cout << endl;
    return 0;
}
