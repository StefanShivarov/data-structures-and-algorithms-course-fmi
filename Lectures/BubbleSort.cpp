#include <iostream>
using namespace std;

//Arrays can be replaced with vectors

//same as std::swap
template <typename T>
void swapElements(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void bubbleSort(T* arr, int length) {

	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				swapElements(arr[j], arr[j + 1]);
			}
		}
	}
}

int main() {

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;
}