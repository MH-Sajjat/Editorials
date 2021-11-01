#include <bits/stdc++.h>
using  namespace std;

template <typename type> void bubbleSort(type ar[], int n) {
    for (int i = 0; i < (n - 1); ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (ar[j] > ar[j + 1]) {
                swap(ar[j], ar[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    int nums[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    bubbleSort(nums, n);
    cout << "Sorted array:";
    for (int i = 0; i < n; ++i) {
        cout << " " << nums[i];
    }
    cout << endl;
    return 0;
}
