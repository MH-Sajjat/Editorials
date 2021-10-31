#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; ++i) cin >> nums[i];
	int findVal;
	cin >> findVal;
	sort(nums, nums + n);
	int left = 0, right = n - 1;
	bool found = 0;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (findVal == nums[mid]) {
			found = 1;
			break;
		} else if (findVal < nums[mid]) right = mid - 1;
		else left = mid + 1;
	}

	if (found) {
		cout << "Found" << endl;
	} else {
		cout << "Not Found" << endl;
	}
	return 0;
}
