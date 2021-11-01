#include <bits/stdc++.h>
using namespace std;

int partition(int ar[], const int l, const int r) {
    int pivot = ar[r];
    int pos = l - 1;
    for (int i = l; i <= (r - 1); ++i) {
        if (ar[i] < pivot) {
            swap(ar[++pos], ar[i]);
        }
    }
    swap(ar[++pos], ar[r]);
    return pos;
}

void quickSort(int ar[], const int l, const int r) {
    if (l >= r) return;
    int pi = partition(ar, l, r);
    quickSort(ar, l, pi - 1);
    quickSort(ar, pi + 1, r);
}

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; ++i) cin >> ar[i];
    quickSort(ar, 0, n - 1);
    cout << "Sorted array:";
    for (int i = 0; i < n; ++i) cout << " " << ar[i];
    cout << endl;
    return 1;
}
