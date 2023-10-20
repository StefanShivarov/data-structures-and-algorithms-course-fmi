int binarySearch(int arr[], int left, int right, int x) {

	while (left <= right) {

		int middle = left + (right - left) / 2;
		if (arr[middle] == x) {
			return middle;
		}

		if (arr[middle] < x) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}

	return -1;
}
