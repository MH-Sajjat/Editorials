#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; ++i) cin >> nums[i];
	int findVal;
	cin >> findVal;
	bool found = 0;
	for (int i = 0; i < n; ++i) {
		if (findVal == nums[i]) {
			found = 1;
			break;
		}
	}
	if (found) {
		cout << "Found" << endl;
	} else {
		cout << "Not Found" << endl;
	}
	return 0;
}
