#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, diff;
	cin >> n >> diff;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int counter = 0;
	for (int i = 0; i < n; i = upper_bound(arr.begin() + i, arr.end(), arr[i]) - arr.begin()) {

		if (arr[i] >= diff && binary_search(arr.begin(), arr.begin() + i, arr[i] - diff)) {
			counter++;
		}
	}
	cout << counter;
}
