#include <iostream>
#include <vector>
using namespace std;

//vector<T> and T[] work the same way when it comes to sorting

template <typename T>
void merge(vector<T>& arr, int left, int middle, int right) {

	int leftLength = middle - left + 1;
	int rightLength = right - middle;

	vector<T> leftArr(leftLength);
	vector<T> rightArr(rightLength);

	for (int i = 0; i < leftLength; i++) {
		leftArr[i] = arr[left + i];
	}

	for (int i = 0; i < rightLength; i++) {
		rightArr[i] = arr[middle + i + 1];
	}

	int leftIndex = 0, rightIndex = 0, mergedIndex = left;

	while (leftIndex < leftLength && rightIndex < rightLength) {

		if (leftArr[leftIndex] <= rightArr[rightIndex]) {
			arr[mergedIndex] = leftArr[leftIndex];
			leftIndex++;
		}
		else {
			arr[mergedIndex] = rightArr[rightIndex];
			rightIndex++;
		}

		mergedIndex++;
	}

	while (leftIndex < leftLength) {
		arr[mergedIndex] = leftArr[leftIndex];
		leftIndex++;
		mergedIndex++;
	}

	while (rightIndex < rightLength) {
		arr[mergedIndex] = rightArr[rightIndex];
		rightIndex++;
		mergedIndex++;
	}
}

template <typename T>
void mergeSort(vector<T>& arr, int left, int right) {

	if (left < right) {
		int middle = left + (right - left) / 2;

		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}

/*
int main() {


	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}
*/
