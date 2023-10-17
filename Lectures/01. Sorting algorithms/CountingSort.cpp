#include <iostream>
#include <vector>
using namespace std;

void countingSort(char* arr, int n) {
	
	char* arrCopy = new char[n];

	for (int i = 0; i < n; i++) {
		arrCopy[i] = arr[i];
	}

	vector<int> count(256, 0);

	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	for (int i = 1; i <= 255; i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		arr[count[arrCopy[i]] - 1] = arrCopy[i];
		count[arrCopy[i]] = count[arrCopy[i]] - 1;
	}

	delete[] arrCopy;
}

/*
int main() {

	int n;
	cin >> n;

	char* arr = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	countingSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}
*/
