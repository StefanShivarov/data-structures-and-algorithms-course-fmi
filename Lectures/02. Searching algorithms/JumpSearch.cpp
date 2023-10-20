#include <vector>
using namespace std;

int jumpSearch(const vector<int>& arr, int x) {

	int length = arr.size();
	int jump = sqrt(length); //length of jump
	int start = 0, end = start + jump;

	while (end < length && arr[end] <= x) {
		start = end;
		end += jump;

		if (end > length - 1) {
			end = length;
		}
	}

	for (int i = start; i < end; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}
