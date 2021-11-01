#include <bits/stdc++.h>
using namespace std;

template <typename type> void heapify(type ar[], int n, int pos) {
    int mx = pos;
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
    if (l < n and ar[l] > ar[mx]) {
        mx = l;
    }
    if (r < n and ar[r] > ar[mx]) {
        mx = r;
    }
    if (mx != pos) {
        swap(ar[mx], ar[pos]);
        heapify(ar, n, mx);
    }
}

template <typename type> void heapSort(type ar[], int n) {
    for (int i = (n / 2) - 1; i >= 0; --i) {
        heapify(ar, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(ar[0], ar[i]);
        heapify(ar, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    int ar[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) cin >> ar[i];
    heapSort(ar, n);
    cout << "Sorted array";
    for (int i = 0; i < n; ++i) cout << " " << ar[i];
    cout << endl;
    return 0;
}
