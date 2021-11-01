#include <bits/stdc++.h>
using namespace std;

void merge(int ar[], const int l, const int mid, const int r) {
    int lSize = mid - l + 1;
    int rSize = r - mid;
    int L[lSize], R[rSize];
    for (int i = 0; i < lSize; ++i) {
        L[i] = ar[l + i];
    }
    for (int i = 0; i < rSize; ++i) {
        R[i] = ar[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < lSize and j < rSize) {
        if (L[i] <= R[j]) {
            ar[k++] = L[i++];
        } else {
            ar[k++] = R[j++];
        }
    }
    while (i < lSize) {
        ar[k++] = L[i++];
    }
    while (j < rSize) {
        ar[k++] = R[j++];
    }
}

void mergeSort(int ar[], const int l, const int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(ar, l, mid);
    mergeSort(ar, mid + 1, r);
    merge(ar, l, mid, r);
}

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    mergeSort(ar, 0, n - 1);
    cout << "Sorted array:";
    for (int i = 0; i < n; ++i) cout << " " << ar[i];
    cout << endl;
    return 0;
}
