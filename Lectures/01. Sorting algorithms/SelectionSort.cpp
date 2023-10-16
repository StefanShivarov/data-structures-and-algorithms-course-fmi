#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T* arr, int length) {

	for (int i = 0; i < length; i++) {
		int minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}

/*
int main() {

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	selectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;

}
*/
