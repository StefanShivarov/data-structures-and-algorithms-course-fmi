int linearSearch(int arr[], int length, int x) {

	for (int i = 0; i < length; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}
