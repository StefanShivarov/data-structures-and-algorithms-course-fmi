#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int partition(vector<T>& arr, int low, int high) {

	T pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

template <typename T>
void quickSort(vector<T>& arr, int low, int high) {

	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

template <typename T>
void quickSort(vector<T>& arr) {
	quickSort(arr, 0, arr.size() - 1);
}

/*
int main() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
*/
