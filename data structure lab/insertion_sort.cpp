#include <bits/stdc++.h>
using namespace std;

void insertionSort(int nums[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 and nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    cout << "Enter the elements: ";
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    insertionSort(nums, n);
    cout << "Sorted array:";
    for (int i = 0; i < n; ++i) {
        cout << " " << nums[i];
    }
    cout << endl;
    return 0;
}
