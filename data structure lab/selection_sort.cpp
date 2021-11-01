#include <bits/stdc++.h>
using namespace std;

void selectionSort(int nums[], int n) {
    for (int i = 0; i < (n - 1); ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[idx]) idx = j;
        }
        swap(nums[i], nums[idx]);
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
    
    selectionSort(nums, n);
    cout << "Sorted array:";
    for (int i = 0; i < n; ++i) {
        cout << " " << nums[i];
    }
    cout << endl;
    return 0;
}
